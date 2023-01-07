#pragma once
#ifndef MOUSE_LISTENER_HPP
#define MOUSE_LISTENER_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

namespace coordinates {
	class MouseListener {
	public:
		virtual void listen(Vector2i);
	};
}

#endif