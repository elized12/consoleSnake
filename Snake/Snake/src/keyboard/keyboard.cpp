#include "keyboard.h"

int KeyBoard::lastPressedKeyCode = -1;

bool KeyBoard::isPressedKey()
{
    if (_kbhit())
    {
        lastPressedKeyCode = _getch();
        return true;
    }
    return false;


}

int KeyBoard::getKeyPressed()
{
    if (lastPressedKeyCode == KeyState::NoPressed)
        throw KeyBoardNoPressed();

    return lastPressedKeyCode;
}
