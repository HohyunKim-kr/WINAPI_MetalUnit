#include "yaBgBossScene.h"
#include "yaResources.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaImage.h"

namespace ya
{
	yaBgBossScene::yaBgBossScene()
		: mImage(nullptr)
	{
	}

	yaBgBossScene::~yaBgBossScene()
	{
	}

	void yaBgBossScene::Initialize()
	{
		// ui_title // bg_forest
		mImage = Resources::Load<Image>(L"Boss", L"..\\Resources\\bg_snow_night_4.bmp");
		GameObject::Initialize();
	}

	void yaBgBossScene::Update()
	{
		GameObject::Update();

		// Transform* tr = GetComponent<Transform>();
		// Vector2 pos = tr->GetPos();
		// tr->SetPos(pos);
	}

	void yaBgBossScene::Render(HDC hdc)
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

	void yaBgBossScene::Release()
	{
		GameObject::Release();
	}
}

