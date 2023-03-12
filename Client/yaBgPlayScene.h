#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class yaBgPlayScene : public GameObject
	{
	public:
		yaBgPlayScene();
		~yaBgPlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}




