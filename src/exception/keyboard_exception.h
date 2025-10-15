#pragma once
#include "exception.h"

class KeyBoardNoPressed : public Exception
{
public:
	KeyBoardNoPressed() : Exception("KeyBoardNoPressed","LastKey Not Init") {}
};