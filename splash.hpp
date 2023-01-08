#pragma once
#ifndef SPLASH_HPP
#define SPLASH_HPP

#include "component_window.hpp"
#include "sprite_button.hpp"
#include <vector>
#include "cell.hpp"
#include "button.hpp"

using namespace interact;
using namespace std;

namespace coordinates {
	class Splash : public ComponentWindow {
		vector<SpriteButton*> checkBtn;
		int checkBtnState = 0, hoverState = -1;
		Button* exitBtn;

		//image selector
		Cell* arg1;
		Button* launchBtn;
		vector<SpriteDrawer*> shovelUnits;
		int shovelUnit = 0;

		Component* addComponent(float, float, float, float);
		void initComponent(Component*, float, float, float, float);
		void initColor(Component*, Color);

	public:
		Splash(int, int, string);
		void drawElements() override;
		void pollEvent(Event) override;
	};
}

#endif