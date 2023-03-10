#pragma once
#include "yaScene.h"
#include "yaImage.h"

namespace ya
{
	class yaBgTitleScene;

	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
	private:
		yaBgTitleScene* mTitleScene;
	};
}