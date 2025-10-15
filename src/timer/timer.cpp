#include "timer.h"


void Timer::tick()
{
	while (!isStop)
	{
		std::this_thread::sleep_for((std::chrono::milliseconds)interval);
		
		
		for (int i = 0; i < events.size(); i++)
			events[i]();
	}
}

timeMills Timer::getTime()
{
	int nowTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	return nowTime - startTime;
}

void Timer::addEvent(std::function<void()> _event)
{
	events.push_back(_event);
}


void Timer::start()
{
	startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().
		time_since_epoch()).count();

	isStop = false;

	timer = std::thread([this] {tick(); });
}

void Timer::stop()
{
	isStop = true;
	
	if (timer.joinable())
		timer.join();

}

Timer::~Timer()
{
	stop();
}



