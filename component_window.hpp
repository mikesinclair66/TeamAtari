#pragma once
#ifndef COMPONENT_WINDOW_HPP
#define COMPONENT_WINDOW_HPP

#include "boundary.hpp"
#include "component.hpp"
#include <string>
#include <vector>

using namespace std;

namespace coordinates {
	class ComponentWindow : public Boundary {
		RenderWindow* window;
		vector<Component*> components;

	public:
		ComponentWindow(int, int, string);
		void add(Component*);
		void draw() override;
		void setSize(Vector2f) override;
		void setPosition(Vector2f) override;
		Vector2f getSize() override;
		Vector2f getPosition() override;
	};
}

#endif