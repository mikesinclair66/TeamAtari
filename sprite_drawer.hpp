#pragma once
#ifndef SPRITE_DRAWER_HPP
#define SPRITE_DRAWER_HPP

#include <SFML/Graphics.hpp>
#include "boundary.hpp"
#include <string>

using namespace sf;
using namespace std;

namespace coordinates {
	class SpriteDrawer : public Boundary {
	protected:
		Texture texture;
		Sprite sprite;

	public:
		SpriteDrawer(string*);
		void draw(RenderWindow&) override;
		void setPosition(float, float) override;
	};
}

#endif