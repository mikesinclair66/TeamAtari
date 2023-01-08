#pragma once
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "boundary.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

namespace coordinates {
	class Component : public Boundary {
	protected:
		RectangleShape rect;
		Color color;

	public:
		virtual void updateColor();
		virtual void draw(RenderWindow&);
		virtual void setColor(Color);
		void setSize(float, float) override;
		void setPosition(float, float) override;
		Color getColor();
		Vector2f getSize() override;
		Vector2f getPosition() override;
	};
}

#endif