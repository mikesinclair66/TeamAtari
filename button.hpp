#pragma once
#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "component.hpp"
#include "mouse_listener.hpp"
#include "alternate_color.hpp"
#include "hidden_component.hpp"
#include <iostream>

using namespace std;
using namespace coordinates;

namespace interact {
	class Button : public Component, public MouseListener,
		public AlternateColorProvider {
		HiddenComponent* hiddenComponent;

	public:
		Button();
		void updateColor() override;
		void draw(RenderWindow&) override;
		void setAlternateColor(Color) override;
		void setSize(float, float) override;
		void setPosition(float, float) override;
		void listen(float, float) override;
	};
}

#endif