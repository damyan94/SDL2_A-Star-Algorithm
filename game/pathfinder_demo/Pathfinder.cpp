// Corresponding header
#include "game/pathfinder_demo/Pathfinder.h"

// C/C++ system includes
#include <iostream>
#include <vector>
#include <algorithm>

// Third-party includes

// Own includes

// ================================================================================
int32_t Pathfinder::init(int32_t w, int32_t h)
{
	if (w > MAX_CELLS_X)
	{
		md.cellsCountX = MAX_CELLS_X;
		std::cerr << "Error, provided cellsCountX is greater than the maximum allowed value of "
			<< MAX_CELLS_X << ". Creating maze with cellsCountX = " << MAX_CELLS_X << std::endl;
	}
	else
	{
		md.cellsCountX = w;
	}

	if (w > MAX_CELLS_Y)
	{
		md.cellsCountY = MAX_CELLS_Y;
		std::cerr << "Error, provided cellsCountY is greater than the maximum allowed value of "
			<< MAX_CELLS_Y << ". Creating maze with cellsCountY = " << MAX_CELLS_Y << std::endl;
	}
	else
	{
		md.cellsCountY = h;
	}

	md.totalCellsCount = md.cellsCountX * md.cellsCountY;

	// Initialize cells
	Cell::initStatic(CELL_WIDTH_HEIGHT, CELL_WIDTH_HEIGHT);

	cells.resize(md.cellsCountX);
	for (auto& cellsColumn : cells)
	{
		cellsColumn.resize(md.cellsCountY);
	}

	using namespace WindowConstants;
	int32_t windowBorderMarginX = (WINDOW_WIDTH - md.cellsCountX * CELL_WIDTH_HEIGHT) / 2;
	int32_t windowBorderMarginY = (WINDOW_HEIGHT - md.cellsCountY * CELL_WIDTH_HEIGHT) / 2;

	for (int32_t i = 0; i < md.cellsCountX; i++) // X
	{
		for (int32_t j = 0; j < md.cellsCountY; j++) // Y
		{
			cells[i][j].init();

			const int32_t drawPosX = windowBorderMarginX + i * CELL_WIDTH_HEIGHT;
			const int32_t drawPosY = windowBorderMarginY + j * CELL_WIDTH_HEIGHT;
			cells[i][j].setDrawPos(drawPosX, drawPosY);
			cells[i][j].setMazePos(i, j);
		}
	}

	// Initialize cell's neighbours vector
	for (int32_t i = 0; i < md.cellsCountX; i++) // X
	{
		for (int32_t j = 0; j < md.cellsCountY; j++) // Y
		{
			std::vector<Cell*> newNeighbours;
			if ((i - 1 >= 0 && i - 1 < MAX_CELLS_X) &&
				(j >= 0 && j < MAX_CELLS_Y))
			{
				newNeighbours.emplace_back(&cells[i - 1][j]);
			}
			if ((i >= 0 && i < MAX_CELLS_X) &&
				(j - 1 >= 0 && j - 1 < MAX_CELLS_Y))
			{
				newNeighbours.emplace_back(&cells[i][j - 1]);
			}
			if ((i + 1 >= 0 && i + 1 < MAX_CELLS_X) &&
				(j >= 0 && j < MAX_CELLS_Y))
			{
				newNeighbours.emplace_back(&cells[i + 1][j]);
			}
			if ((i >= 0 && i < MAX_CELLS_X) &&
				(j + 1 >= 0 && j + 1 < MAX_CELLS_Y))
			{
				newNeighbours.emplace_back(&cells[i][j + 1]);
			}
			cells[i][j].setNeighbours(newNeighbours);
		}
	}

	isInitialized = true;

	return EXIT_SUCCESS;
}

// ================================================================================
void Pathfinder::deinit()
{

}

// ================================================================================
void Pathfinder::handleEvent(const InputEvent& e)
{
	for (auto& cellsRow : cells)
	{
		for (auto& cell : cellsRow)
		{
			cell.handleEvent(e);
		}
	}

	if (e.type == EventType::MOUSE_BUTTONUP)
	{
		md.startCell = Cell::getStartCell();
		md.destCell = Cell::getDestCell();
		md.blockedCellsCount = Cell::getBlockedCellsCount();
		findShortestPath();
	}
}

// ================================================================================
void Pathfinder::update()
{
	
}

// ================================================================================
void Pathfinder::draw() const
{
	for (const auto& cellsRow : cells)
	{
		for (const auto& cell : cellsRow)
		{
			cell.draw();
		}
	}
}

// ================================================================================
void Pathfinder::findShortestPath()
{
	Time t;
	restart();

	// If no start or no dest, return
	if (md.startCell == nullptr || md.destCell == nullptr)
	{
		return;
	}

	// Pathfinding
	std::vector<Cell*> foundCells;
	auto calculateDistance = [](const Point& a, const Point& b)
	{
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	};

	const Point startPos = md.startCell->getMazePos();
	const Point destPos = md.destCell->getMazePos();
	double distanceToGoal = calculateDistance(startPos, destPos);

	md.startCell->asd.parent = nullptr;
	md.startCell->asd.localGoal = 0;
	md.startCell->asd.globalGoal = distanceToGoal;
	foundCells.emplace_back(md.startCell);

	bool keepLooking = true;
	while (keepLooking)
	{
		if (foundCells.size() == 0)
		{
			keepLooking = false;
		}

		auto sortFn = [](Cell* a, Cell* b)
		{
			return a->asd.globalGoal < b->asd.globalGoal;
		};
		std::sort(foundCells.begin(), foundCells.end(), sortFn);
		std::vector<Cell*> cellsToBeCheckedNextRound;

		for (const auto& currCell : foundCells)
		{
			if (currCell->getIsVisited())
			{
				continue;
			}

			if (currCell == md.destCell)
			{
				keepLooking = false;
				continue;
			}

			// Update neighbours
			for (auto& neighbour : currCell->getNeighbours())
			{
				if (currCell->getIsBlocked())
				{
					continue;
				}

				// 1 is the distance between each cell and its neighbours
				int32_t newLocal = currCell->asd.localGoal + 1;
				if (newLocal < neighbour->asd.localGoal)
				{
					const Point nPos = neighbour->getMazePos();
					distanceToGoal = calculateDistance(nPos, destPos);
					neighbour->asd.parent = currCell;
					neighbour->asd.localGoal = newLocal;
					neighbour->asd.globalGoal = newLocal + distanceToGoal;
					cellsToBeCheckedNextRound.emplace_back(neighbour);
				}
			}

			currCell->toggleVisited(true);
		}

		foundCells.clear();
		foundCells.resize(cellsToBeCheckedNextRound.size());
		for (int32_t i = 0; i < (int32_t)foundCells.size(); i++)
		{
			foundCells[i] = cellsToBeCheckedNextRound[i];
		}
	}

	// Update path
	Cell* currCell = md.destCell;
	if (!currCell)
	{
		return;
	}

	keepLooking = true;
	while (keepLooking)
	{
		currCell = currCell->asd.parent;
		if (currCell)
		{
			currCell->toggleValidPath(true);
			md.pathLength++;
		}
		else // Stop looking when the parentPos is nullptr
		{
			keepLooking = false;
		}
	}
	md.pathLength--;
	std::cout << "Time to generate path: " << t.getElapsedTime(UnitsOfTime::MICROSECONDS)
		<< " microseconds." << std::endl;
}

// ================================================================================
const Pathfinder::MazeData& Pathfinder::getMazeData() const
{
	return md;
}

// ================================================================================
bool Pathfinder::getIsInitialized() const
{
	return isInitialized;
}

// ================================================================================
void Pathfinder::restart()
{
	md.pathLength = 0;
	auto sc = md.startCell;
	auto dc = md.destCell;
	auto bcc = md.blockedCellsCount;

	for(auto& cellColumn : cells)
		for (auto& cell : cellColumn)
		{
			cell.restart();
		}
}

// ================================================================================
void Pathfinder::reset()
{
	md.cellsCountX = 0;
	md.cellsCountY = 0;
	md.totalCellsCount = 0;

	md.startCell = nullptr;
	md.destCell = nullptr;
	md.blockedCellsCount = 0;
	md.pathLength = 0;

	for (auto& cellsRow : cells)
	{
		for (auto& cell : cellsRow)
		{
			cell.reset();
		}
	}

	isInitialized = false;
}