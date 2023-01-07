#pragma once
#ifndef TRANSITION_COMPONENT_HPP
#define TRANSITION_COMPONENT_HPP

#include "component.hpp"
#include "timer.hpp"
#include <cmath>

using namespace coordinates;
using namespace util;

namespace interact {
	class TransitionComponent : public Component, public Timer {
		Color transitionColor;
		bool akwardTransition = false;

		enum class TransitionState {
			INACTIVE,
			TRANSITIONING_OUT,
			COMPLETE,
			TRANSITIONING_IN
		};

	public:
		TransitionState transitionState = TransitionState::INACTIVE;
		void updateColor() override;
		void draw(RenderWindow&) override;
		void transition();
		void setColor(Color) override;
		void requestTransition(bool);
	};
}

#endif