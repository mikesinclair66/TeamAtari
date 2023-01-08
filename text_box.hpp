#pragma once
#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include "boundary.hpp"
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

namespace coordinates {
	class TextBox : public Boundary {
		Text text;
		Font font;
		Color color;
		Vector2f size, pos;

	public:
		TextBox();
		void draw(RenderWindow&) override;
		void setSize(float, float) override;
		void setPosition(float, float) override;
		void setString(string);
		void setColor(Color);
		FloatRect getLocalBounds();
		string getString();
	};
}

#endif