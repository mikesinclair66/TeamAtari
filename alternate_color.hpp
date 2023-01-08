#pragma once
#ifndef ALTERNATE_COLOR_HPP
#define ALTERNATE_COLOR_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

namespace coordinates {
	class AlternateColorProvider {
	public:
		virtual void setAlternateColor(Color);
		virtual Color getAlternateColor();
	};
}

#endif