#pragma once
#include "yaScene.h"
#include "yaImage.h"

namespace ya
{
	class Cuphead;
	class yaBgPlayScene;

	class PlayeScene : public Scene
	{
	public:
		PlayeScene();
		~PlayeScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
		
	private:
		Cuphead* mCuphead;
		yaBgPlayScene* mPlayScene;
		
	};
}
