#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class yaBgBossScene : public GameObject
	{
	public:
		yaBgBossScene();
		~yaBgBossScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}




