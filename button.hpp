#pragma once
#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "component.hpp"
#include "mouse_listener.hpp"
#include <iostream>

using namespace std;

namespace coordinates {
	class Button : public Component, public MouseListener {
		bool hovered = false;

	public:
		void listen(float, float) override;
		bool isHovered();
	};
}

#endif