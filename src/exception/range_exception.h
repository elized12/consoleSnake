#pragma once

#include "exception.h"

class Range : public Exception
{
	public:
		Range() : Exception("NotRange","Going beyond") {}
};