#pragma once
#ifndef MOUSE_LISTENER_HPP
#define MOUSE_LISTENER_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

namespace coordinates {
	class MouseListener {
	protected:
		bool hovered, toggled;

	public:
		virtual void listen(float, float);
		virtual bool requestClick();
		virtual void requestRelease();
		bool isHovered();
		bool isToggled();
	};
}

#endif