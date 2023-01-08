#pragma once
#ifndef GRADIENT_HPP
#define GRADIENT_HPP

#include "boundary.hpp"
#include "alternate_color.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

namespace coordinates {
	class Gradient : public Boundary, public AlternateColorProvider {
		Color color, alternateColor;
		Vector2f size;
		Vertex rectangle[4];

	public:
		void setColor(Color);
		void setAlternateColor(Color) override;
		void draw(RenderWindow&) override;
		void setSize(float, float) override;
		void setPosition(float, float) override;
	};
}

#endif