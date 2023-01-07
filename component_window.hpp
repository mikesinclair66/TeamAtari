#pragma once
#ifndef COMPONENT_WINDOW_HPP
#define COMPONENT_WINDOW_HPP

#include <SFML/Window.hpp>
#include "boundary.hpp"
#include "component.hpp"
#include "mouse_listener.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace sf;

namespace coordinates {
	class ComponentWindow : public Boundary {
		RenderWindow* window;
		vector<Component*> components;
		vector<MouseListener*> mouseListeners;

	public:
		ComponentWindow(int, int, string);
		void addComponent(Component*);
		void addMouseListener(MouseListener*);
		void draw() override;
		virtual void pollEvent(Event);
		void setSize(float, float) override;
		void setPosition(float, float) override;
		Vector2f getSize() override;
		Vector2f getPosition() override;
	};
}

#endif