#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Animator;
	class Cuphead : public GameObject
	{
	public:
		enum class eCupheadState
		{
			Move,
			Shoot,
			Death,
			Idle,
		};

		Cuphead();
		~Cuphead();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;
		
	private:
		void move();
		void shoot();
		void death();
		void idle();

	private:
		eCupheadState mState;
		Animator* mAnimator;
	};
}
