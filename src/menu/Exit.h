#pragma once
#include "action.h"
#include <iostream>

class Exit : public Action
{
	public:
		void execute() override;
};