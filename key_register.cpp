#include "key_register.hpp"

using namespace keys;

char KeyRegister::curKey = ' ';
bool KeyRegister::isValid = false;

void KeyRegister::type(Event e) {
	isValid = true;

	switch (e.key.code) {
	case Keyboard::Key::Num0:
		curKey = '0';
		break;
	case Keyboard::Key::Num1:
		curKey = '1';
		break;
	case Keyboard::Key::Num2:
		curKey = '2';
		break;
	case Keyboard::Key::Num3:
		curKey = '3';
		break;
	case Keyboard::Key::Num4:
		curKey = '4';
		break;
	case Keyboard::Key::Num5:
		curKey = '5';
		break;
	case Keyboard::Key::Num6:
		curKey = '6';
		break;
	case Keyboard::Key::Num7:
		curKey = '7';
		break;
	case Keyboard::Key::Num8:
		curKey = '8';
		break;
	case Keyboard::Key::Num9:
		curKey = '9';
		break;
	case Keyboard::Key::BackSpace:
		curKey = '\r';
		break;
	default:
		isValid = false;
		break;
	}
}

char KeyRegister::getRecentKey() {
	return curKey;
}

bool KeyRegister::isValidKey() {
	return isValid;
}