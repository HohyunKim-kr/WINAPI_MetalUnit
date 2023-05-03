#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Rigidbody;
	class Animator;
	class Cuphead : public GameObject
	{
	public:
		enum class eCupheadState
		{
			Move,
			Dash,
			Jump,
			Fall,
			Shoot,
			Attack,
			JumpAttack,
			Death,
			Idle,
		};

		Cuphead();
		~Cuphead();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:
		void move();
		void dash();
		void jump();
		void shoot();
		void attack();
		void death();
		void idle();

		void idleCompleteEvent();

	private:
		eCupheadState mState;
		eDirection mDirect;

		Animator* mAnimator;
		Rigidbody* mRigidbody;
	};
}
