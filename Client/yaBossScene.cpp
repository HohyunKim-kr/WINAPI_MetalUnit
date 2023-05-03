#include "yaBossScene.h"
#include "yaBgBossScene.h"
#include "yaCuphead.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBossMonsterEVE.h"
#include "yaCollisionManager.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaObject.h"
#include "yaGround.h"
#include "yaTilePalatte.h"
namespace ya
{
	BossScene::BossScene()
	{
	}

	BossScene::~BossScene()
	{
	}

	void BossScene::Initialize()
	{
		//mPlayScene = new yaBgPlayScene();
		//AddGameObeject(mPlayScene, eLayerType::BG);

		//mCuphead = new Cuphead();
		//AddGameObeject(mCuphead, eLayerType::Player);

		//Camera::SetTarget(mCuphead);
		Scene::Initialize();
		object::Instantiate<yaBgBossScene>(Vector2(0.0f, 0.0f), eLayerType::BG);
		Cuphead* player = object::Instantiate<Cuphead>(Vector2(300.0f, 300.0f), eLayerType::Player);
		BossMonsterEVE* BossMonster = object::Instantiate<BossMonsterEVE>(Vector2(1200.0f, 300.0f), eLayerType::Boss);
		Ground* ground1 = object::Instantiate<Ground>(Vector2(0.0f, 780.0f), eLayerType::Ground);

		// ground->SetPlayer(player);

		// object::Instantiate<Monster>(Vector2(500.0f, 500.0f), eLayerType::Monster);

		// Monster* monster = new Monster();
		// AddGameObeject(monster, eLayerType::Monster);
		// 
		// monster = new Monster();
		// AddGameObeject(monster, eLayerType::Monster);
		// monster->GetComponent<Transform>()->SetPos(Vector2(300.0f, 500.0f));
	}

	void BossScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Title);
		}
		if (Input::GetKeyDown(eKeyCode::L))
		{
			TilePalatte::Load();
		}
	}

	void BossScene::Render(HDC hdc)
	{
		//Super::Tick();
		Scene::Render(hdc);
	}

	void BossScene::Release()
	{
		Scene::Release();
	}
	void BossScene::OnEnter()
	{
		// Camera::SetTarget(mCuphead);

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Boss, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Boss, eLayerType::Ground, true);

	}
	void BossScene::OnExit()
	{
		//mCuphead->SetPos(Vector2{ 0.0f, 0.0f });
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Boss, false);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, false);
		CollisionManager::SetLayer(eLayerType::Boss, eLayerType::Ground, false);

		Camera::SetTarget(nullptr);

	}
}
