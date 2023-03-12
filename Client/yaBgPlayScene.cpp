#include "yaBgPlayScene.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaResources.h"

namespace ya
{
	yaBgPlayScene::yaBgPlayScene()
	{
	}

	yaBgPlayScene::~yaBgPlayScene()
	{
	}

	void yaBgPlayScene::Initialize()
	{
		mImage = Resources::Load<Image>(L"forest", L"..\\Resources\\ui_title.bmp");
		GameObject::Initialize();
	}

	void yaBgPlayScene::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		tr->SetPos(pos);
	}

	void yaBgPlayScene::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY); 
	}

	void yaBgPlayScene::Release()
	{
		GameObject::Release();
	}
}

