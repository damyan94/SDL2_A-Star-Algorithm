#ifndef CONSOLE_H_
#define CONSOLE_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "defines/FrequentIncludes.h"

// Forward declarations

class Console
{
public:
	int32_t init();
	void deinit();
	void handleEvent(const InputEvent& e);
	void update(int64_t fps);
	void draw() const;

	bool getIsActive() const;

private:
	bool lctrlPressed = false;
	bool isActive = false;
	int32_t consoleHeight = 0;
	Color bgColor = Colors::BLACK;

	struct Logo
	{
		Text name1;
		Text name2;
		Text phone;
		Text email;
		Point pos = Point::UNDEFINED;
	} logo;

	struct Heading
	{
		Text text;
		Text shadow;
		Point pos = Point::UNDEFINED;
	} heading;

	Text textFPS;

	/*struct MemoryData
	{
		Text physicalMemoryUsed;
		Text physicalMemoryTotal;
		Text physicalMemoryFree;
		Text pagingFileTotal;
		Text pagingFileFree;
		Text virtualMemoryTotal;
		Text virtualMemoryFree;
		Text extendedMemoryFree;
		Point pos = Point::UNDEFINED;
	} md;

	struct ProcessMemoryData
	{
		Text pageFaultCount;
		Text peakWorkingSetSize;
		Text workingSetSize;
		Text quotaPeakPagedPoolUsage;
		Text quotaPagedPoolUsage;
		Text quotaPeakNonPagedPoolUsage;
		Text quotaNonPagedPoolUsage;
		Text pagefileUsage;
		Text peakPagefileUsage;
		Point pos = Point::UNDEFINED;
	} pmd;*/
};

#endif // !CONSOLE_H_