#include "yaCuphead.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
	Cuphead::Cuphead()
		:mTime(0.0f)
		,mIdx(0)
	{
	}
	Cuphead::~Cuphead()
	{
	}
	void Cuphead::Initialize()
	{
		mImage = Resources::Load<Image>(L"falcon", L"..\\Resources\\CharacterRun[8].bmp");

		GameObject::Initialize();
	}
	void Cuphead::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Pressed)
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::S) == eKeyState::Pressed)
		{
			pos.y += 100.0f * Time::DeltaTime();
		}
	
		tr->SetPos(pos);
	}
	void Cuphead::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		mTime += Time::DeltaTime();

		if (mIdx >= 8)
		{
			mIdx = 0;
		}

		if (mTime > 0.1f)
		{
			mIdx++;
			mTime = 0.0f;
		}
		TransparentBlt(hdc, pos.x, pos.y, 55, 61, mImage->GetHdc(), (55 * mIdx), 0, 55 , 61, RGB(255, 0, 255));

		
		// BitBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 2, mImage->GetHeight() * 2, mImage->GetHdc(), 0, 0, SRCCOPY);
	}
	void Cuphead::Release()
	{
		GameObject::Release();

	}
}
