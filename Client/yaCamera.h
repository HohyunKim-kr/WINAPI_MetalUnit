#pragma once
#include "YamYamEngine.h"

namespace ya
{
	class GameObject;
	class Camera
	{
	public:
		static void Initiailize();
		static void Update();

		static void SetTarget(GameObject* target) { mTarget = target; }
		static Vector2 CaluatePos(Vector2 pos) { return pos - mDistance; }

	private:
		static Vector2 mResolution;
		static Vector2 mLookPosition;
		static Vector2 mDistance;
		static GameObject* mTarget;
	};
}
