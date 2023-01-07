#include "button.hpp"

using namespace coordinates;

void Button::listen(Vector2i pos) {
	Vector2f tsize = getSize(), tpos = getPosition();
	hovered = pos.x >= tpos.x && pos.x < tpos.x + tsize.x
		&& pos.y >= tpos.y && pos.y < tpos.y + tsize.y;
	cout << "button hovered." << endl;
}

bool Button::isHovered() {
	return hovered;
}