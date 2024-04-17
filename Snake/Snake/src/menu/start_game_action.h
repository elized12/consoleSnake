#pragma once
#include "action.h"
#include "../console/console.h"
#include <chrono>
#include <thread>
#include "../resource/resource.h"
#include "../logic/game.h"



class StartGame : public Action
{
	public:
		void execute() override;
};