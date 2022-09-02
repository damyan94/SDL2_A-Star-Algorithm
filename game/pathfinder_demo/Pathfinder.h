#ifndef PATHFINDER_H_
#define PATHFINDER_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/FrequentIncludes.h"
#include "game/pathfinder_demo/Cell.h"

// Forward declarations

class Pathfinder
{
public:
	static constexpr int32_t CELL_WIDTH_HEIGHT = 24;
	static constexpr int32_t WINDOW_BORDER_MARGIN_X = 100;
	static constexpr int32_t WINDOW_BORDER_MARGIN_Y = 100;
	static constexpr int32_t MAX_CELLS_X = (WindowConstants::WINDOW_WIDTH -
		2 * WINDOW_BORDER_MARGIN_X) / CELL_WIDTH_HEIGHT;
	static constexpr int32_t MAX_CELLS_Y = (WindowConstants::WINDOW_HEIGHT -
		2 * WINDOW_BORDER_MARGIN_X) / CELL_WIDTH_HEIGHT;

public:
	struct MazeData
	{
		int32_t cellsCountX = 0;
		int32_t cellsCountY = 0;
		int32_t totalCellsCount = 0;

		Cell* startCell = nullptr;
		Cell* destCell = nullptr;
		int32_t blockedCellsCount = 0;
		int32_t pathLength = 0;
	}md;

public:
	int32_t init(int32_t w, int32_t h);
	void deinit();
	void handleEvent(const InputEvent& e);
	void update();
	void draw() const;

	void findShortestPath();

	const MazeData& getMazeData() const;
	bool getIsInitialized() const;

	void restart();
	void reset();

private:
	bool isInitialized = false;
	std::vector<std::vector<Cell>> cells;
};

#endif // !PATHFINDER_H_