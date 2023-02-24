#pragma once
#include "yaComponent.h"

// std::map API 끝나고 dx 들어가기전에 한 3~5일 만든다.
// top down 방식
// 이론 -> 연습
// 연습 -> 이론

namespace ya
{
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void SetPos(Vector2 pos) { mPos = pos; }
		void SetSize(Vector2 size) { mSize = size; }
		Vector2 GetPos() { return mPos; }
		Vector2 GetSize() { return mSize; }


	private:
		Vector2 mPos;
		Vector2 mSize;
	};
}
