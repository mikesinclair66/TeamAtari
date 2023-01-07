#pragma once
#ifndef HIDDEN_COMPONENT_HPP
#define HIDDEN_COMPONENT_HPP

#include "component.hpp"

using namespace coordinates;

namespace interact {
	class HiddenComponent : public Component {
		bool shouldDraw = false;

	public:
		void draw(RenderWindow&) override;
		void setVisible(bool);
	};
}

#endif