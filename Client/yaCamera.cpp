#include "yaCamera.h"
#include "yaApplication.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaImage.h"

extern ya::Application application;
namespace ya
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;

	Camera::eCameraEfeectType Camera::mType = Camera::eCameraEfeectType::None;
	class Image* Camera::mCutton = nullptr;
	float Camera::mCuttonAlpha = 1.0f;
	float Camera::mAlphaTime = 0.0f;
	float Camera::mEndTime  = 5.0f;

	void Camera::Initiailize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = (mResolution / 2.0f);

		// mType = eCameraEfeectType::FadeIn;
		mType = eCameraEfeectType::None;
		mCutton = Image::Create(L"Cutton",mResolution.x, mResolution.y, RGB(0, 0, 0));
	}

	void Camera::Update()
	{

		if (Input::GetKey(eKeyCode::LEFT))
			mLookPosition.x -= 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::RIGHT))
			mLookPosition.x += 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::UP))
			mLookPosition.y -= 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::DOWN))
			mLookPosition.y += 100.0f * Time::DeltaTime();


		if (mTarget != nullptr)
		{
			mLookPosition
				= mTarget->GetComponent<Transform>()->GetPos();
		}

		if (mAlphaTime < 5.0f)
		{
			mAlphaTime += Time::DeltaTime();
			float ratio = (mAlphaTime / mEndTime);

			if (mType == eCameraEfeectType::FadeIn)
			{
				mCuttonAlpha = 1.0f - ratio;
			}
			else if (mType == eCameraEfeectType::FadeOut)
			{
				mCuttonAlpha = ratio;
			}
			else
			{
			}
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}

	void Camera::Render(HDC hdc)
	{
		if (mAlphaTime < mEndTime
			&& mType == eCameraEfeectType::FadeIn)
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = 0;
			func.SourceConstantAlpha = (BYTE)(255.0f * mCuttonAlpha);

			AlphaBlend(hdc, 0, 0
				, mResolution.x
				, mResolution.y
				, mCutton->GetHdc()
				, 0, 0
				, mCutton->GetWidth(), mCutton->GetHeight()
				, func);
		}
	}

	void Camera::Clear()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = (mResolution / 2.0f);
		mDistance = Vector2::Zero;
	}
}
