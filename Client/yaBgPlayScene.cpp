#include "yaBgPlayScene.h"
#include "yaResources.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaImage.h"

namespace ya
{
	yaBgPlayScene::yaBgPlayScene()
		: mImage(nullptr)
	{
	}

	yaBgPlayScene::~yaBgPlayScene()
	{
	}

	void yaBgPlayScene::Initialize()
	{
		// ui_title // bg_forest
		mImage = Resources::Load<Image>(L"forest", L"..\\Resources\\bg_forest.bmp");
		GameObject::Initialize();
	}

	void yaBgPlayScene::Update()
	{
		GameObject::Update();

		// Transform* tr = GetComponent<Transform>();
		// Vector2 pos = tr->GetPos();
		// tr->SetPos(pos);
	}

	void yaBgPlayScene::Render(HDC hdc)
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = Camera::CalcuatePos(pos);

		
		/*BitBlt(hdc, 0, 0, mapImage->GetWidth(), mapImage->GetHeight(), mapImage->GetHdc(), 0, 0, SRCCOPY);*/
		TransparentBlt(hdc, pos.x, pos.y, 1600, 900, mImage->GetHdc()
			, 0, 0, mImage->GetWidth(), mImage->GetHeight(), SRCCOPY);
		GameObject::Render(hdc);
		//StretchBlt(hdc, pos.x, pos.y, 1600, 900, mImage->GetHdc()
		//	, 0, 0, mImage->GetWidth(), mImage->GetHeight(), SRCCOPY);

		// GameObject::Render(hdc);
		// Transform* tr = GetComponent<Transform>();
		// Vector2 pos = tr->GetPos();
		// BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY); 
	}

	void yaBgPlayScene::Release()
	{
		GameObject::Release();
	}
}

