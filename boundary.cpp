#include "boundary.hpp"

using namespace coordinates;

void Boundary::draw() {}

void Boundary::setSize(Vector2f size) {}

void Boundary::setPosition(Vector2f pos) {}

Vector2f Boundary::getSize() {
	return Vector2f(-1, -1);
}

Vector2f Boundary::getPosition() {
	return Vector2f(-1, -1);
}