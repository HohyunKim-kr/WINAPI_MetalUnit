#include "yaCuphead.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"

namespace ya
{
	Cuphead::Cuphead()
	{
	}
	Cuphead::~Cuphead()
	{
	}
	void Cuphead::Initialize()
	{
		Image*	mImage = Resources::Load<Image>(L"falcon_Idle", L"..\\Resources\\gp_Idle[5].bmp");
		Image* mImage2 = Resources::Load<Image>(L"falcon_right", L"..\\Resources\\gp_right[8].bmp");
		Image* mImage3 = Resources::Load<Image>(L"falcon_jump", L"..\\Resources\\gp_jump[4].bmp");
		Animator* animator = AddComponent<Animator>();
		animator->CreateAnimation(L"falcon_Idle", mImage, Vector2::Zero, 5, 1, 5, Vector2::Zero, 0.1);
		animator->CreateAnimation(L"falcon_right", mImage2, Vector2::Zero, 8, 1, 8, Vector2::Zero, 0.1);
		animator->CreateAnimation(L"falcon_jump", mImage3, Vector2::Zero, 4, 1, 4, Vector2::Zero, 0.1);

		animator->Play(L"falcon_Idle", true);

		GameObject::Initialize();
	}
	void Cuphead::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		Animator* animator = GetComponent<Animator>();
		if (Input::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::D) == eKeyState::Down)
		{
			animator->Play(L"falcon_right", true);
		}

		if (Input::GetKeyState(eKeyCode::D) == eKeyState::Up)
		{
			animator->Play(L"falcon_Idle", true);
		}

		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Pressed)
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::S) == eKeyState::Pressed)
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::X) == eKeyState::Pressed)
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
		{
			animator->Play(L"falcon_jump", true);
		}

		if (Input::GetKeyState(eKeyCode::X) == eKeyState::Up)
		{
			animator->Play(L"falcon_Idle", true);
		}
	
		tr->SetPos(pos);
	}
	void Cuphead::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		// Transform* tr = GetComponent<Transform>();
		// Vector2 pos = tr->GetPos();
		// 
		// mTime += Time::DeltaTime();
		// 
		// if (mIdx >= 8)
		// {
		// 	mIdx = 0;
		// }
		// 
		// if (mTime > 0.1f)
		// {
		// 	mIdx++;
		// 	mTime = 0.0f;
		// }
		// TransparentBlt(hdc, pos.x, pos.y, 55, 61, mImage->GetHdc(), (55 * mIdx), 0, 55 , 61, RGB(255, 0, 255));

		
		// BitBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 2, mImage->GetHeight() * 2, mImage->GetHdc(), 0, 0, SRCCOPY);
	}
	void Cuphead::Release()
	{
		GameObject::Release();

	}
}
