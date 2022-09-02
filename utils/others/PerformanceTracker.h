#ifndef PERFORMANCE_TRACKER_H_
#define PERFORMANCE_TRACKER_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations

namespace PerformanceTracker
{
	struct MemoryData
	{
		unsigned long long physicalMemoryUsed = 0;
		unsigned long long physicalMemoryTotal = 0;
		unsigned long long physicalMemoryFree = 0;
		unsigned long long pagingFileTotal = 0;
		unsigned long long pagingFileFree = 0;
		unsigned long long virtualMemoryTotal = 0;
		unsigned long long virtualMemoryFree = 0;
		unsigned long long extendedMemoryFree = 0;
	};
	MemoryData getMemoryData();

	struct ProcessMemoryData
	{
		unsigned long long pageFaultCount = 0;
		unsigned long long peakWorkingSetSize = 0;
		unsigned long long workingSetSize = 0;
		unsigned long long quotaPeakPagedPoolUsage = 0;
		unsigned long long quotaPagedPoolUsage = 0;
		unsigned long long quotaPeakNonPagedPoolUsage = 0;
		unsigned long long quotaNonPagedPoolUsage = 0;
		unsigned long long pagefileUsage = 0;
		unsigned long long peakPagefileUsage = 0;
	};
	ProcessMemoryData getProcessMemoryData();
};

#endif // !PERFORMANCE_TRACKER_H_