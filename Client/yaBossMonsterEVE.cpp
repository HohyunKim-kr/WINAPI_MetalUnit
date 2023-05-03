#include "yaBossMonsterEVE.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaBaseBullet.h"
#include "yaScene.h"
#include "yaRigidbody.h"

namespace ya
{
	BossMonsterEVE::BossMonsterEVE()
	{
	}
	BossMonsterEVE::~BossMonsterEVE()
	{
	}
	void BossMonsterEVE::Initialize()
	{
		// Transform* tr = GetComponent<Transform>();
		// tr->SetPos(Vector2(700.0f, 400.0f));
		// tr->SetScale(Vector2(1.5f, 1.5f));
		Transform* tr = GetComponent<Transform>();
		tr->SetPos(Vector2(400.0f, 400.0f));
		tr->SetScale(Vector2(3.f, 3.f));

		Image* mImage = Resources::Load<Image>(L"gp_monster_boss_EVE", L"..\\Resources\\eve_boss[18].bmp");

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"gp_monster_boss_EVE", mImage, Vector2::Zero, 18, 1, 18, Vector2::Zero, 0.1f);

		mAnimator->Play(L"gp_monster_boss_EVE", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-50.0f, -80.0f));
		collider->SetSize(Vector2(300.0f, 300.0f));

		//mRigidbody = AddComponent<Rigidbody>();
		//mRigidbody->SetMass(1.0f);

		//mRigidbody = AddComponent<Rigidbody>();
		//mRigidbody->SetMass(1.0f);

		GameObject::Initialize();
	}
	void BossMonsterEVE::Update()
	{
		//mRigidbody->AddForce(Vector2(0.0f, 0.0f));

		GameObject::Update();
	}
	void BossMonsterEVE::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void BossMonsterEVE::Release()
	{
		GameObject::Release();
	}
}