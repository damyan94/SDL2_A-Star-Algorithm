// Corresponding header
#include "utils/time/Timer.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

std::unordered_map<int32_t, Timer::TimerUnit> Timer::_timers;
Time Timer::_globalTime;

void Timer::startGlobalTimer()
{
	_globalTime.getElapsedTime(UnitsOfTime::MILLISECONDS);
}

// The default unit of time for the timers is a millisecond
void Timer::startTimer(int32_t id, int64_t interval, TimerType timerType)
{
	if (interval < TIMER_MIN_INTERVAL)
	{
		std::cout << "Error, Timer::init() received invalid interval: " << interval << std::endl;
		return;
	}

	if (_timers.find(id) != _timers.end())
	{
		std::cout << "Error, found existing timer with the same id: " << id << std::endl;
		return;
	}

	_timers[id]._timerType = timerType;
	_timers[id]._interval = interval;
	_timers[id]._remaining = interval;
}

void Timer::destroyTimer(int32_t id)
{
	if (_timers.find(id) == _timers.end())
	{
		std::cout << "Error, Timer::destroyTimer() received invalid timer id: " << id << std::endl;
		return;
	}

	_timers.erase(id);
}

void Timer::updateTimers()
{
	int64_t elapsedTime = _globalTime.getElapsedTime(UnitsOfTime::MILLISECONDS);

	for (auto& timer : _timers)
	{
		timer.second._remaining -= elapsedTime;

		if (timer.second._remaining < 0)
		{
			timer.second._remaining += timer.second._interval;
			timer.second._ticked = true;
		}
	}
}

bool Timer::timerTicked(int32_t id)
{
	if (_timers.find(id) == _timers.end())
	{
		std::cout << "Error, Timer::timerTicked() received invalid timer id: " << id << std::endl;
		return false;
	}

	if (_timers[id]._ticked)
	{
		_timers[id]._ticked = false;

		if (_timers[id]._timerType == TimerType::ONE_SHOT)
			Timer::destroyTimer(id);

		return true;
	}

	else
		return false;
}

bool Timer::isActiveTimer(int32_t id)
{
	if (_timers.find(id) == _timers.end())
		return false;

	else
		return true;
}