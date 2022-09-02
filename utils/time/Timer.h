#ifndef TIMER_H_
#define TIMER_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/time/Time.h"

// Forward declarations

constexpr int64_t TIMER_MIN_INTERVAL = 20;

enum class TimerType
{
	ONE_SHOT,
	PULSE
};

class Timer
{
public:
	Timer() = delete;
	~Timer() = default;

	static void startGlobalTimer();

	static void startTimer(int32_t id, int64_t interval, TimerType timerType);
	static void destroyTimer(int32_t id);
	static void updateTimers();

	static bool timerTicked(int32_t id);
	static bool isActiveTimer(int32_t id);

private:
	struct TimerUnit
	{
		TimerType _timerType = TimerType::ONE_SHOT;
		int64_t _interval = 0;
		int64_t _remaining = 0;
		bool _ticked = false;
	};

	static std::unordered_map<int32_t, TimerUnit> _timers;
	static Time _globalTime;
};

#endif // !TIMER_H_