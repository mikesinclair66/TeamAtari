#include "button.hpp"

using namespace coordinates;

void Button::listen(float x, float y) {
	Vector2f tsize = getSize(), tpos = getPosition();
	hovered = x >= tpos.x && x < tpos.x + tsize.x
		&& y >= tpos.y && y < tpos.y + tsize.y;
}

bool Button::isHovered() {
	return hovered;
}