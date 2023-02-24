#pragma once
#include "yaComponent.h"

// std::map API ������ dx �������� �� 3~5�� �����.
// top down ���
// �̷� -> ����
// ���� -> �̷�

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
