#include "component.hpp"

using namespace coordinates;

void Component::draw(RenderWindow& window) {
	window.draw(rect);
}

void Component::setColor(Color color) {
	rect.setFillColor(color);
}

void Component::setSize(float width, float height) {
	rect.setSize(Vector2f(width, height));
}

void Component::setPosition(float x, float y) {
	rect.setPosition(Vector2f(x, y));
}

Vector2f Component::getSize() {
	return rect.getSize();
}

Vector2f Component::getPosition() {
	return rect.getPosition();
}