#include "sprite_button.hpp"

using namespace interact;

SpriteButton::SpriteButton(string path) : SpriteDrawer(path) {
	setSize(60, 57);
}

void SpriteButton::listen(float x, float y) {
	hovered = x >= pos.x && x < pos.x + size.x
		&& y >= pos.y && y < pos.y + size.y;
}

void SpriteButton::setSize(float width, float height) {
	SpriteDrawer::setSize(width, height);
	size = Vector2f(width, height);
}

void SpriteButton::setPosition(float x, float y) {
	SpriteDrawer::setPosition(x, y);
	pos = Vector2f(x, y);
}