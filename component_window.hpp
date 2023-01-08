#pragma once
#ifndef COMPONENT_WINDOW_HPP
#define COMPONENT_WINDOW_HPP

#include <SFML/Window.hpp>
#include "boundary.hpp"
#include "component.hpp"
#include "mouse_listener.hpp"
#include <string>
#include <vector>
#include "key_register.hpp"
#include "key_listener.hpp"

using namespace std;
using namespace sf;
using namespace keys;

namespace coordinates {
	class ComponentWindow : public Boundary {
		vector<Boundary*> boundaries;
		vector<MouseListener*> mouseListeners;
		vector<KeyListener*> keyListeners;

	protected:
		RenderWindow* window;

	public:
		ComponentWindow(int, int, string);
		void addBoundary(Boundary*);
		void addMouseListener(MouseListener*);
		void addKeyListener(KeyListener*);
		void draw() override;
		virtual void drawElements();
		virtual void pollEvent(Event);
		void setSize(float, float) override;
		void setPosition(float, float) override;
		Vector2f getSize() override;
		Vector2f getPosition() override;
	};
}

#endif