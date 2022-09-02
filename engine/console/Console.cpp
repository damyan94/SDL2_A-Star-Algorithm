// Corresponding header
#include "engine/console/Console.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "utils/others/PerformanceTracker.h"

// ================================================================================
int32_t Console::init()
{
	consoleHeight = 480;
	bgColor = Colors::BLACK;
	bgColor.a = 239;

	// Init logo
	logo.name1.init("Damyan", FontId::ROG_36, Colors::WHITE);
	logo.name2.init("Damyanov", FontId::ROG_36, Colors::WHITE);
	logo.phone.init("+359 879 928 857", FontId::CONSOLA_24, Colors::WHITE);
	logo.email.init("damyandamyanov_94@yahoo.com", FontId::CONSOLA_24, Colors::WHITE);

	logo.pos = Point(16, -16);
	logo.name1.setPos(logo.pos.x, logo.pos.y);
	logo.name2.setPos(logo.pos.x, logo.pos.y + 18);
	logo.phone.setPos(logo.pos.x + 180, logo.pos.y + 24);
	logo.email.setPos(logo.pos.x + 180, logo.pos.y + 42);

	// Init heading
	heading.text.init("Welcome to the console menu.", FontId::ROG_72, Colors::WHITE);
	heading.shadow.init("Welcome to the console menu.", FontId::ROG_72, Colors::GREY);

	heading.pos = Point((WindowConstants::WINDOW_WIDTH - heading.text.getWidth()) / 2, 48);
	heading.text.setPos(heading.pos.x, heading.pos.y);
	heading.shadow.setPos(heading.pos.x + 2, heading.pos.y + 2);

	// This text is set in the update() function.
	textFPS.init("0", FontId::CONSOLA_24, Colors::WHITE);

	textFPS.setPos(40, 210 + 32 * 0);

	//// Init memory data
	//md.physicalMemoryUsed.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//md.physicalMemoryTotal.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//md.physicalMemoryFree.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//md.pagingFileTotal.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//md.pagingFileFree.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//md.virtualMemoryTotal.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//md.virtualMemoryFree.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//md.extendedMemoryFree.init("0", FontId::CONSOLA_24, Colors::WHITE);

	//md.pos = Point(40, 180);
	//md.physicalMemoryUsed.setPos(md.pos.x, md.pos.y + 0 * 32);
	//md.physicalMemoryTotal.setPos(md.pos.x, md.pos.y + 1 * 32);
	//md.physicalMemoryFree.setPos(md.pos.x, md.pos.y + 2 * 32);
	//md.pagingFileTotal.setPos(md.pos.x, md.pos.y + 3 * 32);
	//md.pagingFileFree.setPos(md.pos.x, md.pos.y + 4 * 32);
	//md.virtualMemoryTotal.setPos(md.pos.x, md.pos.y + 5 * 32);
	//md.virtualMemoryFree.setPos(md.pos.x, md.pos.y + 6 * 32);
	//md.extendedMemoryFree.setPos(md.pos.x, md.pos.y + 7 * 32);

	//// Init process memory data
	//pmd.pageFaultCount.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//pmd.peakWorkingSetSize.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//pmd.workingSetSize.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//pmd.quotaPeakPagedPoolUsage.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//pmd.quotaPagedPoolUsage.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//pmd.quotaPeakNonPagedPoolUsage.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//pmd.quotaNonPagedPoolUsage.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//pmd.pagefileUsage.init("0", FontId::CONSOLA_24, Colors::WHITE);
	//pmd.peakPagefileUsage.init("0", FontId::CONSOLA_24, Colors::WHITE);

	//pmd.pos = Point(540, 180);
	//pmd.pageFaultCount.setPos(pmd.pos.x, pmd.pos.y + 0 * 32);
	//pmd.peakWorkingSetSize.setPos(pmd.pos.x, pmd.pos.y + 1 * 32);
	//pmd.workingSetSize.setPos(pmd.pos.x, pmd.pos.y + 2 * 32);
	//pmd.quotaPeakPagedPoolUsage.setPos(pmd.pos.x, pmd.pos.y + 3 * 32);
	//pmd.quotaPagedPoolUsage.setPos(pmd.pos.x, pmd.pos.y + 4 * 32);
	//pmd.quotaPeakNonPagedPoolUsage.setPos(pmd.pos.x, pmd.pos.y + 5 * 32);
	//pmd.quotaNonPagedPoolUsage.setPos(pmd.pos.x, pmd.pos.y + 6 * 32);
	//pmd.pagefileUsage.setPos(pmd.pos.x, pmd.pos.y + 7 * 32);
	//pmd.peakPagefileUsage.setPos(pmd.pos.x, pmd.pos.y + 8 * 32);

	return EXIT_SUCCESS;
}

// ================================================================================
void Console::deinit()
{

}

// ================================================================================
void Console::handleEvent(const InputEvent& e)
{
	if (e.type == EventType::KEYBOARD_PRESS && e.key == Keyboard::KEY_LEFT_CTRL)
	{
		lctrlPressed = true;
	}

	else if (e.type == EventType::KEYBOARD_RELEASE && e.key == Keyboard::KEY_LEFT_CTRL)
	{
		lctrlPressed = false;
	}

	if (!lctrlPressed)
	{
		return;
	}

	if (e.type == EventType::KEYBOARD_RELEASE && e.key == Keyboard::KEY_BACKQUOTE)
	{
		isActive = !isActive;
	}
}

// ================================================================================
void Console::update(int64_t fps)
{
	if (!isActive)
	{
		return;
	}

	textFPS.setText(("FPS: " + std::to_string(fps)).c_str());

	//// Update memory data
	//PerformanceTracker::MemoryData systemData = PerformanceTracker::getMemoryData();
	//md.physicalMemoryUsed.setText(("Physical memory used: " + std::to_string(systemData.physicalMemoryUsed) + " %").c_str());
	//md.physicalMemoryTotal.setText(("Physical memory total: " + std::to_string(systemData.physicalMemoryTotal) + " KB").c_str());
	//md.physicalMemoryFree.setText(("Physical memory free: " + std::to_string(systemData.physicalMemoryFree) + " KB").c_str());
	//md.pagingFileTotal.setText(("Paging file total: " + std::to_string(systemData.pagingFileTotal) + " KB").c_str());
	//md.pagingFileFree.setText(("Paging file free: " + std::to_string(systemData.pagingFileFree) + " KB").c_str());
	//md.virtualMemoryTotal.setText(("Virtual memory total: " + std::to_string(systemData.virtualMemoryTotal) + " KB").c_str());
	//md.virtualMemoryFree.setText(("Virtual memory free: " + std::to_string(systemData.virtualMemoryFree) + " KB").c_str());
	//md.extendedMemoryFree.setText(("Extended memory free: " + std::to_string(systemData.extendedMemoryFree) + " KB").c_str());

	//// Update process memory data
	//PerformanceTracker::ProcessMemoryData processData = PerformanceTracker::getProcessMemoryData();
	//pmd.pageFaultCount.setText(("Physical memory used: " + std::to_string(processData.pageFaultCount) + " KB").c_str());
	//pmd.peakWorkingSetSize.setText(("Peak working set size: " + std::to_string(processData.peakWorkingSetSize) + " KB").c_str());
	//pmd.workingSetSize.setText(("Working set size: " + std::to_string(processData.workingSetSize) + " KB").c_str());
	//pmd.quotaPeakPagedPoolUsage.setText(("Quota peak paged pool usage: " + std::to_string(processData.quotaPeakPagedPoolUsage) + " KB").c_str());
	//pmd.quotaPagedPoolUsage.setText(("Quota paged pool usage: " + std::to_string(processData.quotaPagedPoolUsage) + " KB").c_str());
	//pmd.quotaPeakNonPagedPoolUsage.setText(("PQuota peak non paged pool usage: " + std::to_string(processData.quotaPeakNonPagedPoolUsage) + " KB").c_str());
	//pmd.quotaNonPagedPoolUsage.setText(("Quota non paged pool usage: " + std::to_string(processData.quotaNonPagedPoolUsage) + " KB").c_str());
	//pmd.pagefileUsage.setText(("Page file usage: " + std::to_string(processData.pagefileUsage) + " KB").c_str());
	//pmd.peakPagefileUsage.setText(("Peak page file usage: " + std::to_string(processData.peakPagefileUsage) + " KB").c_str());
}

// ================================================================================
void Console::draw() const
{
	if (!isActive)
	{
		return;
	}

	SDLDrawing::drawFilledRectangle(0, 0, WindowConstants::WINDOW_WIDTH, consoleHeight, bgColor);

	// Draw logo
	logo.name1.draw();
	logo.name2.draw();
	logo.phone.draw();
	logo.email.draw();
	SDLDrawing::drawLine(logo.pos.x + 170, logo.pos.y + 22, logo.pos.x + 170, logo.pos.y + 66, Colors::WHITE);
	SDLDrawing::drawLine(logo.pos.x - 10, logo.pos.y + 66, logo.pos.x + 540, logo.pos.y + 66, Colors::WHITE);

	// Draw heading
	heading.shadow.draw();
	heading.text.draw();
	int32_t linePosX = heading.pos.x;
	int32_t linePosY = heading.pos.y + heading.text.getHeight() + 2;
	SDLDrawing::drawFilledRectangle(linePosX + 2, linePosY + 2, heading.text.getWidth(), 4, Colors::GREY);
	SDLDrawing::drawFilledRectangle(linePosX, linePosY, heading.text.getWidth(), 4, Colors::WHITE);

	textFPS.draw();

	//// Draw memory data
	//md.physicalMemoryUsed.draw();
	//md.physicalMemoryTotal.draw();
	//md.physicalMemoryFree.draw();
	//md.pagingFileTotal.draw();
	//md.pagingFileFree.draw();
	//md.virtualMemoryTotal.draw();
	//md.virtualMemoryFree.draw();
	//md.extendedMemoryFree.draw();
	//
	//// Draw process memory data
	//pmd.pageFaultCount.draw();
	//pmd.peakWorkingSetSize.draw();
	//pmd.workingSetSize.draw();
	//pmd.quotaPeakPagedPoolUsage.draw();
	//pmd.quotaPagedPoolUsage.draw();
	//pmd.quotaPeakNonPagedPoolUsage.draw();
	//pmd.quotaNonPagedPoolUsage.draw();
	//pmd.pagefileUsage.draw();
	//pmd.peakPagefileUsage.draw();
}

// ================================================================================
bool Console::getIsActive() const
{
	return isActive;
}