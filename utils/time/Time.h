#ifndef TIME_H_
#define TIME_H_

// C/C++ system includes
#include <cstdint>
#include <chrono>

// Third-party includes

// Own includes

// Forward declarations

enum class UnitsOfTime
{
	HOURS,
	MINUTES,
	SECONDS,
	MILLISECONDS,
	MICROSECONDS,
	NANOSECONDS
};

class Time
{
public:
	int64_t getElapsedTime(UnitsOfTime unit);

private:
	std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point elapsedTime;
};

#endif // !TIME_H_