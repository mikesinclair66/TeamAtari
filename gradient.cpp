#include "gradient.hpp"

using namespace coordinates;

Gradient::Gradient() : SpriteDrawer(nullptr) {}

void Gradient::setColor(Color color) {
	this->color = color;
}

void Gradient::setAlternateColor(Color alternateColor) {
	this->alternateColor = alternateColor;
}

void Gradient::setSize(float width, float height) {
	Boundary::setSize(width, height);
	image.create(width, height);

	//create gradient
	for (int r = 0; r < height; r++) {
		Color distCol(
			color.r + (alternateColor.r - color.r) * (r / height),
			color.g + (alternateColor.g - color.g) * (r / height),
			color.b + (alternateColor.b - color.b) * (r / height),
			color.a + (alternateColor.a - color.a) * (r / height)
		);

		cout << "R: " << distCol.r << endl;
		cout << "G: " << distCol.g << endl;
		cout << "B: " << distCol.b << endl;
		cout << "A: " << distCol.a << endl;

		for (int c = 0; c < width; c++)
			image.setPixel(c, r, distCol);
	}

	texture.update(image);
	texture.setSmooth(true);
	sprite.setTexture(texture);
}

void Gradient::setPosition(float x, float y) {
	Boundary::setPosition(x, y);
}