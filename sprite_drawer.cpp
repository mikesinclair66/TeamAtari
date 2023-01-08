#include "sprite_drawer.hpp"

using namespace coordinates;

SpriteDrawer::SpriteDrawer(string path) {
	if (path != "") {
		if (!texture.loadFromFile(path)) {}
		sprite.setTexture(texture);
	}
}

void SpriteDrawer::draw(RenderWindow& window) {
	Boundary::draw(window);
	window.draw(sprite);
}

void SpriteDrawer::setPosition(float x, float y) {
	Boundary::setPosition(x, y);
	sprite.setPosition(x, y);
}