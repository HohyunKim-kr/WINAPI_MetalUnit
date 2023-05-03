#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Rigidbody;
	class Animator;
	class BossMonsterEVE : public GameObject
	{
	public:
		BossMonsterEVE();
		~BossMonsterEVE();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
		Rigidbody* mRigidbody;
	};
}


