#pragma once
#include <chrono>
#include <thread>
#include <vector>
#include <functional>

typedef unsigned long long timeMills;


class Timer 
{
	private:
		timeMills startTime;
		timeMills interval;
		std::vector<std::function<void()>> events;
		std::thread timer;
		volatile bool isStop;
	private:
		void tick();
	public:
		Timer(timeMills _interval) : interval(_interval), startTime(0), isStop(false){}
		Timer(const Timer& a) = delete;
	public:
		timeMills getTime();		
	public:
		void addEvent(std::function<void()> event);
		void start();
		void stop();
	public:
		virtual ~Timer();
};