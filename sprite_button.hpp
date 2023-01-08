#pragma once
#ifndef SPRITE_BUTTON_HPP
#define SPRITE_BUTTON_HPP

#include "sprite_drawer.hpp"
#include "mouse_listener.hpp"
#include <string>
#include <iostream>

using namespace coordinates;
using namespace std;

namespace interact {
	class SpriteButton : public SpriteDrawer, public MouseListener {
		Vector2f size, pos;

	public:
		SpriteButton(string);
		void listen(float, float) override;
		void setSize(float, float) override;
		void setPosition(float, float) override;
	};
}

#endif