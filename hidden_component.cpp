#include "hidden_component.hpp"

using namespace interact;

void HiddenComponent::draw(RenderWindow& window) {
	if (shouldDraw)
		Component::draw(window);
}

void HiddenComponent::setVisible(bool shouldDraw) {
	this->shouldDraw = shouldDraw;
}