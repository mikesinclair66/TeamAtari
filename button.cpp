#include "button.hpp"

using namespace interact;

Button::Button() {
	hiddenComponent = new HiddenComponent();
}

void Button::updateColor() {
	Component::updateColor();
	hiddenComponent->updateColor();
}

void Button::draw(RenderWindow& window) {
	Component::draw(window);
	hiddenComponent->draw(window);
}

void Button::setAlternateColor(Color color) {
	hiddenComponent->setColor(color);
}

void Button::setSize(float width, float height) {
	Component::setSize(width, height);
	hiddenComponent->setSize(width, height);
}

void Button::setPosition(float x, float y) {
	Component::setPosition(x, y);
	hiddenComponent->setPosition(x, y);
}

void Button::listen(float x, float y) {
	Vector2f tsize = getSize(), tpos = getPosition();
	bool hovered = x >= tpos.x && x < tpos.x + tsize.x
		&& y >= tpos.y && y < tpos.y + tsize.y;

	if (hovered != this->hovered) {
		hiddenComponent->setVisible(hovered);
		this->hovered = hovered;
	}
}

bool Button::isHovered() {
	return hovered;
}