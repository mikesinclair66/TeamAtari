#pragma once
#ifndef CELL_HPP
#define CELL_HPP

#include "button.hpp"
#include "text_box.hpp"
#include <SFML/Graphics.hpp>
#include "timer.hpp"
#include "key_listener.hpp"

using namespace coordinates;
using namespace sf;
using namespace util;
using namespace keys;

namespace interact {
	class Cell : public Button, public KeyListener {
		bool cursorChanged = false;

	public:
		RectangleShape textIndicator;
		Timer tiTimer;
		TextBox* textBox;
		Cursor cursor;

		Cell();
		void type(char) override;
		bool requestClick() override;
		void requestRelease() override;
		void draw(RenderWindow&) override;
		void setSize(float, float) override;
		void setPosition(float, float) override;
		void setTextIndicatorColor(Color);
	};
}

#endif