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
		void setSize(Vector2f) override;
		void setPosition(Vector2f) override;
		Vector2f getSize() override;
		Vector2f getPosition() override;
	};
}

#endif