#pragma once
#ifndef KEY_REGISTER_HPP
#define KEY_REGISTER_HPP

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;
using namespace std;

namespace keys {
	class KeyRegister {
		static char curKey;
		static bool isValid;

	public:
		static void type(Event);
		static char getRecentKey();
		static bool isValidKey();
	};
}

#endif