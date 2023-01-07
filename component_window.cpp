#include "component_window.hpp"

using namespace coordinates;

ComponentWindow::ComponentWindow(int width, int height, string label) {
	window = new RenderWindow(VideoMode(width, height), label.c_str());
}

void ComponentWindow::add(Component* component) {
	components.push_back(component);
}

void ComponentWindow::draw() {
	Boundary::draw();

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event))
		{
			switch (event.type) {
			case Event::Closed:
				window->close();
				break;
			case Event::Resized:
				View view = window->getDefaultView();
				view.setSize({
					static_cast<float>(event.size.width),
					static_cast<float>(event.size.height)
					});
				window->setView(view);
				break;
			}
		}

		window->clear();
		for (Component* component : components)
			component->draw(*window);
		window->display();
	}
}

void ComponentWindow::setSize(Vector2f size) {
	Boundary::setSize(size);
	window->setSize(Vector2u(size.x, size.y));
}

void ComponentWindow::setPosition(Vector2f pos) {
	Boundary::setPosition(pos);
	window->setPosition(Vector2i(pos.x, pos.y));
}

Vector2f ComponentWindow::getSize() {
	Vector2u cwSize = window->getSize();
	return Vector2f(cwSize.x, cwSize.y);
}

Vector2f ComponentWindow::getPosition() {
	Vector2i cwPos = window->getPosition();
	return Vector2f(cwPos.x, cwPos.y);
}