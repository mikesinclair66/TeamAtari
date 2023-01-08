#include "text_box.hpp"

using namespace coordinates;

TextBox::TextBox() {
	if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf")) {}
	text.setFont(font);
	text.setCharacterSize(24);
}

void TextBox::draw(RenderWindow& window) {
	text.setFillColor(color);
	FloatRect bounds = text.getLocalBounds();
	text.setOrigin(Vector2f(bounds.left + bounds.width / 2.f,
		bounds.top + bounds.height / 2.f));
	window.draw(text);
}

void TextBox::setSize(float width, float height) {
	Boundary::setSize(width, height);
	size = Vector2f(width, height);
}

void TextBox::setPosition(float x, float y) {
	Boundary::setPosition(x, y);
	pos = Vector2f(x, y);
	text.setPosition(Vector2f(x + getSize().x / 2, y + getSize().y / 2));
}

void TextBox::setString(string label) {
	text.setString(label);
}

void TextBox::setColor(Color color) {
	this->color = color;
}

FloatRect TextBox::getLocalBounds() {
	return text.getLocalBounds();
}

string TextBox::getString() {
	return text.getString();
}