#pragma once
#include "YamYamEngine.h"

namespace ya
{
	class GameObject;
	class Camera
	{
	public:
		enum class eCameraEfeectType
		{
			None,
			FadeIn,
			FadeOut,
			End,
		};

		static void Initiailize();
		static void Update();
		static void Render(HDC hdc);
		static void Clear();

		static void SetTarget(GameObject* target) { mTarget = target; }
		static Vector2 CalcuatePos(Vector2 pos) { return pos - mDistance; }

	private:
		static Vector2 mResolution;
		static Vector2 mLookPosition;
		static Vector2 mDistance;
		static GameObject* mTarget;
		
		static eCameraEfeectType mType;
		static class Image* mCutton;
		static float mCuttonAlpha;
		static float mAlphaTime;
		static float mEndTime;
	};
}
