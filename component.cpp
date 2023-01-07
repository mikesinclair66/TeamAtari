#include "component.hpp"

using namespace coordinates;

void Component::draw(RenderWindow& window) {
	window.draw(rect);
}

void Component::setColor(Color color) {
	rect.setFillColor(color);
}

void Component::setSize(Vector2f size) {
	rect.setSize(size);
}

void Component::setPosition(Vector2f pos) {
	rect.setPosition(pos);
}

Vector2f Component::getSize() {
	return rect.getSize();
}

Vector2f Component::getPosition() {
	return rect.getPosition();
}