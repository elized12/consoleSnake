#pragma once
#include <conio.h>
#include "../exception/keyboard_exception.h"
enum KeyState
{
	NoPressed = -30000,
	Pressed = 1
};


enum KeyCode
{
	ArrowLeft = 75,
	ArrowRight = 77,
	ArrowUP = 72,
	ArrowDown = 80,
	Esc = 27
};


class KeyBoard
{
	private:
		KeyBoard() = delete;
		static int lastPressedKeyCode;
	public:

		static bool isPressedKey();
		static int getKeyPressed() throw(KeyBoardNoPressed);


};

