#pragma once
#ifndef DROPDOWN_MENU_HPP
#define DROPDOWN_MENU_HPP

#include "button.hpp"
#include "component.hpp"

using namespace coordinates;

namespace interact {
	class Dropdown : public Button {
	public:
		Component* dropdown;
		Dropdown();
		void draw(RenderWindow&);
		void setPosition(float, float) override;
	};
}

#endif