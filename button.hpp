#pragma once
#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "component.hpp"
#include "mouse_listener.hpp"
#include "hidden_component.hpp"
#include <iostream>

using namespace std;

namespace interact {
	class Button : public Component, public MouseListener {
		HiddenComponent* hiddenComponent;
		bool hovered = false;

	public:
		Button();
		void updateColor() override;
		void draw(RenderWindow&) override;
		void setAlternateColor(Color);
		void setSize(float, float) override;
		void setPosition(float, float) override;
		void listen(float, float) override;
		bool isHovered();
	};
}

#endif