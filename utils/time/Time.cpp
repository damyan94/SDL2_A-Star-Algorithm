// Corresponding header
#include "utils/time/Time.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

int64_t Time::getElapsedTime(UnitsOfTime unit)
{
	elapsedTime = startTime;
	startTime = std::chrono::steady_clock::now();
	auto duration = startTime - elapsedTime;

	int64_t lastLap = 0;

	switch (unit)
	{
	case UnitsOfTime::HOURS:
		lastLap = std::chrono::duration_cast<std::chrono::hours>(duration).count();
		break;

	case UnitsOfTime::MINUTES:
		lastLap = std::chrono::duration_cast<std::chrono::minutes>(duration).count();
		break;

	case UnitsOfTime::SECONDS:
		lastLap = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
		break;

	case UnitsOfTime::MICROSECONDS:
		lastLap = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
		break;

	case UnitsOfTime::MILLISECONDS:
		lastLap = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
		break;

	case UnitsOfTime::NANOSECONDS:
		lastLap = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
		break;

	default:
		break;
	}

	return lastLap;
}