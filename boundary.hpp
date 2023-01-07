#pragma once
#ifndef BOUNDARY_HPP
#define BOUNDARY_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

namespace coordinates {
	class Boundary {
	public:
		virtual void draw();
		virtual void setSize(float, float);
		virtual void setPosition(float, float);
		virtual Vector2f getSize();
		virtual Vector2f getPosition();
	};
}

#endif