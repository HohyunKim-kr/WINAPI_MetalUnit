#include "yaCuphead.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaBaseBullet.h"
#include "yaScene.h"
#include "yaObject.h"
#include "yaRigidbody.h"

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

		Transform* tr = GetComponent<Transform>();
		tr->SetPos(Vector2(400.0f, 400.0f));
		tr->SetScale(Vector2(2.f, 2.f));

		Image*	mImage = Resources::Load<Image>(L"falcon_Idle", L"..\\Resources\\gp_Idle[5].bmp");
		Image* mImage2 = Resources::Load<Image>(L"falcon_right", L"..\\Resources\\gp_right[8].bmp");
		Image* mImage3 = Resources::Load<Image>(L"falcon_jump", L"..\\Resources\\gp_jump[4].bmp");
		Image* mImage4 = Resources::Load<Image>(L"gp_unit_gun", L"..\\Resources\\gp_unit_FalconUnit_renewer_attack[3].bmp");
		Image* mImage5 = Resources::Load<Image>(L"gp_unit_sword", L"..\\Resources\\gp_unit_FalconUnit_renewer_attack2.bmp");

		mAnimator = AddComponent<Animator>();
		// mAnimator->CreateAnimation(L"IdleR", mImageR, Vector2(120.0f * 0, 120.0f * 0), 120.0f, 30, 60, 4, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"falcon_Idle", mImage, Vector2::Zero, 5, 1, 5, Vector2::Zero, 0.1f);
		mAnimator->CreateAnimation(L"falcon_right", mImage2, Vector2::Zero, 8, 1, 8, Vector2::Zero, 0.1f);
		mAnimator->CreateAnimation(L"falcon_jump", mImage3, Vector2::Zero, 4, 1, 4, Vector2::Zero, 0.1f);
		mAnimator->CreateAnimation(L"gp_unit_gun", mImage4, Vector2::Zero, 3, 1, 3, Vector2::Zero, 0.1f);
		mAnimator->CreateAnimation(L"gp_unit_sword", mImage5, Vector2::Zero, 4, 4, 4, Vector2::Zero, 0.1f);

		// mAnimator->CreateAnimations(L"..\\Resources\\gp_unit_FalconUnit_renewer_attack[3]", Vector2::Zero, 0.1f);

		mAnimator->Play(L"falcon_Idle", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-20.0f, -50.0f));
		collider->SetSize(Vector2(80.0f, 95.0f));

		mRigidbody = AddComponent<Rigidbody>();
		mRigidbody->SetMass(1.0f);

		mState = eCupheadState::Idle;

		GameObject::Initialize();
	}
	void Cuphead::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case ya::Cuphead::eCupheadState::Move:
			move();
			break;
		case ya::Cuphead::eCupheadState::Dash:
			dash();
			break;
		case ya::Cuphead::eCupheadState::Shoot:
			shoot();
			break;
		case ya::Cuphead::eCupheadState::Attack:
			attack();
			break;
		case ya::Cuphead::eCupheadState::Death:
			death();
			break;
		case ya::Cuphead::eCupheadState::Idle:
			idle();
			break;
		default:
			break;
		}

		/*
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
		*/
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
	void Cuphead::OnCollisionEnter(Collider* other)
	{

	}
	void Cuphead::OnCollisionStay(Collider* other)
	{
		 
	}
	void Cuphead::OnCollisionExit(Collider* other)
	{

	}
	void Cuphead::move()
	{
		if (Input::GetKeyUp(eKeyCode::A)
			|| Input::GetKeyUp(eKeyCode::D)
			|| Input::GetKeyUp(eKeyCode::S)
			|| Input::GetKeyUp(eKeyCode::W)
			|| Input::GetKeyDown(eKeyCode::SPACE))
		{
			mState = eCupheadState::Idle;
			mAnimator->Play(L"falcon_Idle", true);
		}

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::A))
			mRigidbody->AddForce(Vector2(-200.0f, 0.0f));
			//pos.x -= 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::D))
			mRigidbody->AddForce(Vector2(200.0f, 0.0f));
			//pos.x += 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::W))
			mRigidbody->AddForce(Vector2(0.0f, -200.0f));
			//pos.y -= 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::S))
			mRigidbody->AddForce(Vector2(0.0f, 200.0f));
			//pos.y += 100.0f * Time::DeltaTime();

		tr->SetPos(pos);
	}
	// void Cuphead::jump()
	// {
	// 	if (Input::GetKeyDown(eKeyCode::SPACE))
	// 	{
	// 		Vector2 velocity = mRigidbody->GetVelocity();
	// 		velocity.y -= 500.0f;
	// 
	// 		mRigidbody->SetVelocity(velocity);
	// 		mRigidbody->SetGround(false);
	// 	}
	// 	else
	// 	{
	// 		mState = eCupheadState::Idle;
	// 		mAnimator->Play(L"falcon_Idle", true);
	// 	}
	// }
	void Cuphead::dash()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::SHIFT))
		{
			mRigidbody->AddForce(Vector2(400.0f, 0.0f));
		}
		else
		{
			mState = eCupheadState::Idle;
			mAnimator->Play(L"falcon_Idle", true);
		}
	}
	void Cuphead::shoot()
	{
		Transform* tr = GetComponent<Transform>();

		if (Input::GetKey(eKeyCode::RBUTTON))
		{
			// object::Instantiate<BaseBullet>(Vector2(400.0f, 400.0f), eLayerType::Bullet);
			Scene* curScene = SceneManager::GetActiveScene();
			BaseBullet* bullet = new BaseBullet();
			bullet->GetComponent<Transform>()->SetPos(tr->GetPos());
			curScene->AddGameObeject(bullet, eLayerType::Bullet);
		}
		else
		{
			mState = eCupheadState::Idle;
			mAnimator->Play(L"falcon_Idle", true);		
		}
	}
	void Cuphead::attack()
	{
		Transform* tr = GetComponent<Transform>();

		if(Input::GetKey(eKeyCode::LBUTTON))
		{
			
		}
		else
		{
			mState = eCupheadState::Idle;
			mAnimator->Play(L"falcon_Idle", true);
		}
	}
	void Cuphead::death()
	{
	}
	
	void Cuphead::idle()
	{
		if (Input::GetKeyDown(eKeyCode::A)
			|| Input::GetKeyDown(eKeyCode::D)
			|| Input::GetKeyDown(eKeyCode::S)
			|| Input::GetKeyDown(eKeyCode::W)
			|| Input::GetKeyDown(eKeyCode::SPACE))
		{
			mState = eCupheadState::Move;
			mAnimator->Play(L"falcon_right", true);
		}

		if (Input::GetKeyDown(eKeyCode::SPACE))
		{
			Vector2 velocity = mRigidbody->GetVelocity();
			velocity.y -= 500.0f;
			
			mRigidbody->SetVelocity(velocity);
			mRigidbody->SetGround(false);
		
			mState = eCupheadState::Move;
			mAnimator->Play(L"falcon_jump", true);
		}

		if (Input::GetKeyDown(eKeyCode::RBUTTON))
		{
			mState = eCupheadState::Shoot;
			mAnimator->Play(L"gp_unit_gun", true);
		}

		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			mState = eCupheadState::Attack;
			mAnimator->Play(L"gp_unit_sword", true);
		}

		if (Input::GetKeyDown(eKeyCode::SHIFT))
		{
			mState = eCupheadState::Dash;
			mAnimator->Play(L"gp_unit_sword", true);
		}
	}

	void Cuphead::idleCompleteEvent(/*const Cuphead* this*/)
	{
		int a = 0;
		//mState =
		//Transform* tr = GetComponent<Transform>();
		//Scene* curScene = SceneManager::GetActiveScene();
		//BaseBullet* bullet = new BaseBullet();
		//bullet->GetComponent<Transform>()->SetPos(tr->GetPos());
		//curScene->AddGameObeject(bullet, eLayerType::Bullet);
	}
}
