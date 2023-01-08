#include "mouse_listener.hpp"

using namespace coordinates;

void MouseListener::listen(float, float) {}

bool MouseListener::requestClick() {
	toggled = hovered;
	return toggled;
}

void MouseListener::requestRelease() {}

bool MouseListener::isHovered() {
	return hovered;
}

bool MouseListener::isToggled() {
	return toggled;
}