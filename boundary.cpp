#include "boundary.hpp"

using namespace coordinates;

void Boundary::draw() {}

void Boundary::draw(RenderWindow& window) {}

void Boundary::setSize(float width, float height) {}

void Boundary::setPosition(float x, float y) {}

Vector2f Boundary::getSize() {
	return Vector2f(-1, -1);
}

Vector2f Boundary::getPosition() {
	return Vector2f(-1, -1);
}