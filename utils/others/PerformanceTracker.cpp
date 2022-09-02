// Corresponding header
#include "utils/others/PerformanceTracker.h"

// C/C++ system includes
#include <iostream>
#include <thread>

// Third-party includes

// Own includes

#if defined(WIN32) || defined(_WIN32)
#include <Windows.h>
#include <psapi.h>
#include <stdio.h>
#include <tchar.h>
#define DIV 1024
#define WIDTH 7
#endif // !WIN32 || _WIN32

PerformanceTracker::MemoryData PerformanceTracker::getMemoryData()
{
	PerformanceTracker::MemoryData result;

#if defined(WIN32) || defined(_WIN32)
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);

	result.physicalMemoryUsed = statex.dwMemoryLoad;
	result.physicalMemoryTotal = statex.ullTotalPhys / DIV;
	result.physicalMemoryFree = statex.ullAvailPhys / DIV;
	result.pagingFileTotal = statex.ullTotalPageFile / DIV;
	result.pagingFileFree = statex.ullAvailPageFile / DIV;
	result.virtualMemoryTotal = statex.ullTotalVirtual / DIV;
	result.virtualMemoryFree = statex.ullAvailVirtual / DIV;
	result.extendedMemoryFree = statex.ullAvailExtendedVirtual / DIV;
#endif // !WIN32 || _WIN32

	return result;
}

PerformanceTracker::ProcessMemoryData PerformanceTracker::getProcessMemoryData()
{
    PerformanceTracker::ProcessMemoryData result;

#if defined(WIN32) || defined(_WIN32)
    HANDLE hProcess = GetCurrentProcess();
    if (!hProcess)
        return result;

    PROCESS_MEMORY_COUNTERS pmc;

    if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
    {
        result.pageFaultCount = pmc.PageFaultCount;
        result.peakWorkingSetSize = pmc.PeakWorkingSetSize;
        result.workingSetSize = pmc.WorkingSetSize;
        result.quotaPeakPagedPoolUsage = pmc.QuotaPeakPagedPoolUsage;
        result.quotaPagedPoolUsage = pmc.QuotaPagedPoolUsage;
        result.quotaPeakNonPagedPoolUsage = pmc.QuotaPeakNonPagedPoolUsage;
        result.quotaNonPagedPoolUsage = pmc.QuotaNonPagedPoolUsage;
        result.pagefileUsage = pmc.PagefileUsage;
        result.peakPagefileUsage = pmc.PeakPagefileUsage;
    }

    CloseHandle(hProcess);
#endif // !WIN32 || _WIN32

    return result;
}