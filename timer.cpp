#include "timer.hpp"

using namespace util;

void Timer::setGoalTime(float goalTime) {
	this->goalTime = goalTime;
}

void Timer::clear() {
	clock.restart();
	flipped = false;
}

void Timer::flipRatio() {
	awkwardRatio = 1.f - ratio;
	clock.restart();
	flipped = true;
}

float Timer::getRatio(bool inversed) {
	float ratio = clock.getElapsedTime().asMilliseconds() / goalTime;

	if (flipped)
		ratio += awkwardRatio;
	if (inversed)
		ratio = 1.f - ratio;
	return ratio;
}