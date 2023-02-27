#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Cuphead : public GameObject
	{
	public:
		Cuphead();
		~Cuphead();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;
		
	private:
		Image* mImage;
		float mTime;
		int mIdx;
	};
}
