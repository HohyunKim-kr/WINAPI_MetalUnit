#include "yaBgTitleScene.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaResources.h"

namespace ya
{
	yaBgTitleScene::yaBgTitleScene()
	{
	}
	yaBgTitleScene::~yaBgTitleScene()
	{
	}
	void yaBgTitleScene::Initialize()
	{
		mImage = Resources::Load<Image>(L"title", L"..\\Resources\\bg_forest.bmp");
		GameObject::Initialize();
	}
	void yaBgTitleScene::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		tr->SetPos(pos);
	}
	void yaBgTitleScene::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}
	void yaBgTitleScene::Release()
	{
		GameObject::Release();
	}
}