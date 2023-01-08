#include "gradient.hpp"

using namespace coordinates;

void Gradient::setColor(Color color) {
	this->color = color;
}

void Gradient::setAlternateColor(Color alternateColor) {
	this->alternateColor = alternateColor;
}

void Gradient::draw(RenderWindow& window) {
	Boundary::draw(window);
	window.draw(rectangle, 4, Quads);
}

void Gradient::setSize(float width, float height) {
	Boundary::setSize(width, height);
	size = Vector2f(width, height);
}

void Gradient::setPosition(float x, float y) {
	Boundary::setPosition(x, y);
	rectangle[0] = Vertex(Vector2f(x, y), color);
	rectangle[1] = Vertex(Vector2f(x + size.x, y), color);
	rectangle[2] = Vertex(Vector2f(x + size.x, y + size.y), alternateColor);
	rectangle[3] = Vertex(Vector2f(x, y + size.y), alternateColor);
}