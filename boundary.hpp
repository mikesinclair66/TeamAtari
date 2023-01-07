#pragma once
#ifndef BOUNDARY_HPP
#define BOUNDARY_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

namespace coordinates {
	class Boundary {
	public:
		virtual void draw();
		virtual void setSize(Vector2f);
		virtual void setPosition(Vector2f);
		virtual Vector2f getSize();
		virtual Vector2f getPosition();
	};
}

#endif