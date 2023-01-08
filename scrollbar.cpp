#include "scrollbar.hpp"

using namespace interact;

Scrollbar::Scrollbar() {
	scrollBtn = new Button();
}

void Scrollbar::listen(float x, float y) {
	scrollBtn->listen(x, y);
}

bool Scrollbar::requestClick() {
	MouseListener::requestClick();
	return scrollBtn->requestClick();
}

void Scrollbar::requestRelease() {}

void Scrollbar::draw(RenderWindow& window) {
	Component::draw(window);
	scrollBtn->draw(window);
}

void Scrollbar::setScrollColors(Color defaultColor, Color activeColor) {
	scrollBtn->setColor(defaultColor);
	scrollBtn->setAlternateColor(activeColor);
	scrollBtn->updateColor();
}

void Scrollbar::setRatio(float ratio) {
	this->ratio = ratio;
}

void Scrollbar::setOffsetRatio(float offsetRatio) {
	this->offsetRatio = offsetRatio;
}

void Scrollbar::updateOffsetRatio(float x, float y) {}

float Scrollbar::getBarSize(float dimension) {
	return dimension * ratio;
}

float Scrollbar::getBarOffset(float dimension) {
	return dimension * offsetRatio;
}

ScrollbarVertical::ScrollbarVertical() : Scrollbar() {}

void ScrollbarVertical::listen(float x, float y) {
	Scrollbar::listen(x, y);
}

void ScrollbarVertical::setSize(float width, float height) {
	Scrollbar::setSize(width, height);
	scrollBtn->setSize(width, getBarSize(height));
}

void ScrollbarVertical::setPosition(float x, float y) {
	Scrollbar::setPosition(x, y);
	updateOffsetRatio(x, y);
}

void ScrollbarVertical::updateOffsetRatio(float x, float y) {
	Scrollbar::updateOffsetRatio(x, y);
	scrollBtn->setPosition(x, y + getBarOffset(getSize().y));
}

ScrollbarHorizontal::ScrollbarHorizontal() : Scrollbar() {}

void ScrollbarHorizontal::listen(float x, float y) {
	Scrollbar::listen(x, y);
}

void ScrollbarHorizontal::setSize(float width, float height) {
	Scrollbar::setSize(width, height);
	scrollBtn->setSize(getBarSize(width), height);
}

void ScrollbarHorizontal::setPosition(float x, float y) {
	Scrollbar::setPosition(x, y);
	updateOffsetRatio(x, y);
}

void ScrollbarHorizontal::updateOffsetRatio(float x, float y) {
	Scrollbar::updateOffsetRatio(x, y);
	scrollBtn->setPosition(x + getBarOffset(getSize().x), y);
}