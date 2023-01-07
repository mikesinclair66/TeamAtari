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
		void clear();
		void flipRatio();
		float getRatio(bool = false);

	public:
		void setGoalTime(float);
	};
}

#endif