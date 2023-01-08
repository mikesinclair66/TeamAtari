#include "component.hpp"

using namespace coordinates;

void Component::updateColor() {
	rect.setFillColor(color);
}

void Component::draw(RenderWindow& window) {
	Boundary::draw(window);
	window.draw(rect);
}

void Component::setColor(Color color) {
	this->color = color;
}

void Component::setSize(float width, float height) {
	rect.setSize(Vector2f(width, height));
}

void Component::setPosition(float x, float y) {
	rect.setPosition(Vector2f(x, y));
}

Color Component::getColor() {
	return color;
}

Vector2f Component::getSize() {
	return rect.getSize();
}

Vector2f Component::getPosition() {
	return rect.getPosition();
}