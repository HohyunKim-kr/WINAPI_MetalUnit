#include "yaPlayeScene.h"
#include "yaBgPlayScene.h"
#include "yaCuphead.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaObject.h"
#include "yaGround.h"
#include "yaTilePalatte.h"
namespace ya
{
	PlayeScene::PlayeScene()
	{
	}

	PlayeScene::~PlayeScene()
	{
	}

	void PlayeScene::Initialize()
	{
		//mPlayScene = new yaBgPlayScene();
		//AddGameObeject(mPlayScene, eLayerType::BG);

		//mCuphead = new Cuphead();
		//AddGameObeject(mCuphead, eLayerType::Player);

		//Camera::SetTarget(mCuphead);
		Scene::Initialize();
		object::Instantiate<yaBgPlayScene>(Vector2(0.0f, 0.0f), eLayerType::BG);
		Cuphead* player = object::Instantiate<Cuphead>(Vector2(300.0f, 300.0f), eLayerType::Player);
		Monster* monster = object::Instantiate<Monster>(Vector2(1000.0f, 780.0f), eLayerType::Monster);
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

	void PlayeScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Boss);
		}
		if (Input::GetKeyDown(eKeyCode::L))
		{
			TilePalatte::Load();
		}
	}

	void PlayeScene::Render(HDC hdc)
	{
		//Super::Tick();
		Scene::Render(hdc);
	}

	void PlayeScene::Release()
	{
		Scene::Release();
	}
	void PlayeScene::OnEnter()
	{
		// Camera::SetTarget(mCuphead);

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Ground, true);

	}
	void PlayeScene::OnExit()
	{
		//mCuphead->SetPos(Vector2{ 0.0f, 0.0f });
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, false);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, false);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Ground, false);

		Camera::SetTarget(nullptr);

	}
}
