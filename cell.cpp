#include "cell.hpp"

using namespace interact;

Cell::Cell() {
	textBox = new TextBox();
	tiTimer.setGoalTime(1000);
}

void Cell::type(char key) {
	if (toggled) {
		string preString = textBox->getString();
		switch (key) {
		case '\r':
			textBox->setString(preString.substr(0, preString.length() - 1));
			break;
		default:
			textBox->setString(preString + key);
			break;
		}
	}
}

bool Cell::requestClick() {
	bool clicked = Button::requestClick();
	if (clicked)
		tiTimer.clear();
	return clicked;
}

void Cell::requestRelease() {
	Button::requestRelease();
	if (!isHovered())
		toggled = false;
}

void Cell::draw(RenderWindow& window) {
	Component::draw(window);
	textBox->draw(window);

	if ((isHovered() && !cursorChanged) || (!isHovered() && cursorChanged)) {
		cursorChanged = !cursorChanged;
		if (cursorChanged) {
			if (cursor.loadFromSystem(Cursor::Text))
				window.setMouseCursor(cursor);
		}
		else {
			if (cursor.loadFromSystem(Cursor::Arrow))
				window.setMouseCursor(cursor);
		}
	}

	if (toggled) {
		if (tiTimer.getRatio() < 0.5f) {
			FloatRect bounds = textBox->getLocalBounds();
			textIndicator.setPosition(Vector2f(getPosition().x + getSize().x / 2
				+ bounds.width / 2 + 3, getPosition().y + 11));
			window.draw(textIndicator);
		}
		else if (tiTimer.getRatio() >= 1.f)
			tiTimer.clear();
	}
}

void Cell::setSize(float width, float height) {
	Component::setSize(width, height);
	textBox->setSize(width, height);
	textIndicator.setSize(Vector2f(4, height - 22));
}

void Cell::setPosition(float x, float y) {
	Component::setPosition(x, y);
	textBox->setPosition(x + getSize().x / 2, y + getSize().y / 2);
}

void Cell::setTextIndicatorColor(Color tiColor) {
	textIndicator.setFillColor(tiColor);
}