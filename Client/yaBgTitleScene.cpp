#include "yaBgTitleScene.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaResources.h"
#include "yaCamera.h"

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
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = Camera::CalcuatePos(pos);

		GameObject::Render(hdc);
		/*BitBlt(hdc, 0, 0, mapImage->GetWidth(), mapImage->GetHeight(), mapImage->GetHdc(), 0, 0, SRCCOPY);*/
		StretchBlt(hdc, pos.x, pos.y, 1600, 900, mImage->GetHdc()
			, 0, 0, mImage->GetWidth(), mImage->GetHeight(), SRCCOPY);
		// GameObject::Render(hdc);
		// Transform* tr = GetComponent<Transform>();
		// Vector2 pos = tr->GetPos();
		// BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}
	void yaBgTitleScene::Release()
	{
		GameObject::Release();
	}
}