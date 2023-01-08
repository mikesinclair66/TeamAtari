#pragma once
#ifndef TIMER_HPP
#define TIMER_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace sf;
using namespace std;

namespace util {
	class Timer {
		float ratio, awkwardRatio, goalTime;
		bool flipped;
		Clock clock;

	protected:
		void flipRatio();

	public:
		void clear();
		void setGoalTime(float);
		float getRatio(bool = false);
	};
}

#endif