#include "component_window.hpp"

using namespace coordinates;

ComponentWindow::ComponentWindow(int width, int height, string label) {
	window = new RenderWindow(VideoMode(width, height),
		label.c_str(), Style::None);
}

void ComponentWindow::addBoundary(Boundary* boundary) {
	boundaries.push_back(boundary);
}

void ComponentWindow::addMouseListener(MouseListener* mouseListener) {
	mouseListeners.push_back(mouseListener);
}

void ComponentWindow::addKeyListener(KeyListener* keyListener) {
	keyListeners.push_back(keyListener);
}

void ComponentWindow::draw() {
	Boundary::draw();

	while (window->isOpen()) {
		Event event;
		while (window->pollEvent(event))
			pollEvent(event);

		window->clear();
		drawElements();
		window->display();
	}
}

void ComponentWindow::drawElements() {
	for (Boundary* boundary : boundaries)
		boundary->draw(*window);
}

void ComponentWindow::pollEvent(Event e) {
	View view;
	switch (e.type) {
	case Event::Closed:
		window->close();
		break;
	case Event::Resized:
		view = window->getDefaultView();
		view.setSize({
			static_cast<float>(e.size.width),
			static_cast<float>(e.size.height)
			});
		window->setView(view);
		break;
	case Event::MouseMoved:
		for (MouseListener* ml : mouseListeners)
			ml->listen(e.mouseMove.x, e.mouseMove.y);
		break;
	case Event::MouseButtonPressed:
		for (MouseListener* ml : mouseListeners)
			ml->requestClick();
		break;
	case Event::MouseButtonReleased:
		for (MouseListener* ml : mouseListeners)
			ml->requestRelease();
	case Event::KeyPressed:
		KeyRegister::type(e);
		if (KeyRegister::isValidKey()) {
			for (KeyListener* kl : keyListeners)
				kl->type(KeyRegister::getRecentKey());
		}
		break;
	}
}

void ComponentWindow::setSize(float width, float height) {
	Boundary::setSize(width, height);
	window->setSize(Vector2u(width, height));
}

void ComponentWindow::setPosition(float x, float y) {
	Boundary::setPosition(x, y);
	window->setPosition(Vector2i(x, y));
}

Vector2f ComponentWindow::getSize() {
	Vector2u cwSize = window->getSize();
	return Vector2f(cwSize.x, cwSize.y);
}

Vector2f ComponentWindow::getPosition() {
	Vector2i cwPos = window->getPosition();
	return Vector2f(cwPos.x, cwPos.y);
}