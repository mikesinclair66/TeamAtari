#include "transition_component.hpp"

using namespace interact;

void TransitionComponent::updateColor() {
	rect.setFillColor(transitionColor);
}

void TransitionComponent::draw(RenderWindow& window) {
	transition();
	Component::draw(window);
}

void TransitionComponent::transition() {
	if (transitionState != TransitionState::INACTIVE
		&& transitionState != TransitionState::COMPLETE) {
		auto getTransitionColor = [](float ratio, Color color) {
			return Color(color.r, color.g, color.b, color.a * ratio);
		};

		bool ratioActive = getRatio() < 1.f;
		switch (transitionState) {
		case TransitionState::TRANSITIONING_OUT:
			if(ratioActive)
				transitionColor = getTransitionColor(getRatio(), color);
			else {
				transitionColor = color;
				transitionState = TransitionState::COMPLETE;
			}
			break;
		case TransitionState::TRANSITIONING_IN:
			if(ratioActive)
				transitionColor = getTransitionColor(getRatio(true), color);
			else {
				transitionColor = Color(color.r, color.g, color.b, 0);
				transitionState = TransitionState::INACTIVE;
			}
			break;
		}

		rect.setFillColor(transitionColor);
	}
}

void TransitionComponent::setColor(Color color) {
	Component::setColor(color);
	transitionColor = Color(color.r, color.g, color.b, 0);
}

void TransitionComponent::requestTransition(bool hoverFlipped) {
	if (hoverFlipped) {
		if (transitionState == TransitionState::TRANSITIONING_OUT
			|| transitionState == TransitionState::TRANSITIONING_IN)
			flipRatio();
		else
			clear();

		switch (transitionState) {
		case TransitionState::COMPLETE:
		case TransitionState::TRANSITIONING_OUT:
			transitionState = TransitionState::TRANSITIONING_IN;
			break;

		case TransitionState::INACTIVE:
		case TransitionState::TRANSITIONING_IN:
			transitionState = TransitionState::TRANSITIONING_OUT;
			break;
		}
	}
}