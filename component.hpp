#pragma once
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "boundary.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

namespace coordinates {
	class Component : public Boundary {
		RectangleShape rect;

	public:
		void draw(RenderWindow&);
		void setColor(Color);
		void setSize(float, float) override;
		void setPosition(float, float) override;
		Vector2f getSize() override;
		Vector2f getPosition() override;
	};
}

#endif