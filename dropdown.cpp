#include "dropdown.hpp"

using namespace interact;

Dropdown::Dropdown() {
	dropdown = new Component();
}

void Dropdown::draw(RenderWindow& window) {
	Button::draw(window);
	if (toggled)
		dropdown->draw(window);
}

void Dropdown::setPosition(float x, float y) {
	Button::setPosition(x, y);
	dropdown->setPosition(x, y + getSize().y);
}