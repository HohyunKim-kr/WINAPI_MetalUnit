#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Tile : public GameObject
	{
	public:
		Tile();
		Tile(Vector2 pos);
		~Tile();

		void InitializeTile(Image* atlas, int index);
		void SetIndex(int index);

		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mAtlas;
		int mIndex;
		int mX;
		int mY;
	};
}
