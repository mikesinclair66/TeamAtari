#pragma once
#ifndef GRADIENT_HPP
#define GRADIENT_HPP

#include "sprite_drawer.hpp"
#include <SFML/Graphics.hpp>
#include "alternate_color.hpp"
#include <iostream>

using namespace coordinates;
using namespace sf;
using namespace std;

namespace coordinates {
	class Gradient : public SpriteDrawer, public AlternateColorProvider {
		Image image;
		Color color, alternateColor;

	public:
		Gradient();
		void setColor(Color);
		void setAlternateColor(Color) override;
		void setSize(float, float);
		void setPosition(float, float);
	};
}

#endif