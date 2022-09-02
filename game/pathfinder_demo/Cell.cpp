// Corresponding header
#include "game/pathfinder_demo/Cell.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

// Static private constants and variables
Color Cell::colorEmpty = Color(0, 0, 255, 127);
Color Cell::colorStart = Colors::YELLOW;
Color Cell::colorFinish = Colors::ORANGE;
Color Cell::colorBlocked = Colors::RED;
Color Cell::colorVisited = Colors::BLUE;
Color Cell::colorValidPath = Colors::GREEN;

static int32_t cellWidth;
static int32_t cellHeight;

Cell* Cell::startCell;
Cell* Cell::destCell;
int32_t Cell::blockedCellsCount;

// ================================================================================
int32_t Cell::initStatic(int32_t w, int32_t h)
{
	colorEmpty = Color(0, 0, 255, 127);
	colorStart = Colors::YELLOW;
	colorFinish = Colors::ORANGE;
	colorBlocked = Colors::RED;
	colorVisited = Colors::BLUE;
	colorValidPath = Colors::GREEN;

	cellWidth = w;
	cellHeight = h;

	startCell = nullptr;
	destCell = nullptr;
	blockedCellsCount = 0;

	return EXIT_SUCCESS;
}

// ================================================================================
int32_t Cell::init()
{
	reset();

	return EXIT_SUCCESS;
}

// ================================================================================
void Cell::deinit()
{

}

// ================================================================================
void Cell::handleEvent(const InputEvent& e)
{
	bool isInsideCell = e.pos.x >= drawPos.x && e.pos.x <= drawPos.x + cellWidth &&
		e.pos.y >= drawPos.y && e.pos.y <= drawPos.y + cellHeight;

	if (!isInsideCell)
	{
		return;
	}

	if (e.type == EventType::MOUSE_BUTTONUP && e.mouse == Mouse::RIGHT_BUTTON)
	{
		toggleBlocked();
	}
	else if (e.type == EventType::MOUSE_BUTTONUP && e.mouse == Mouse::LEFT_BUTTON)
	{
		toggleStartFinish();
	}
}

// ================================================================================
void Cell::update()
{

}

// ================================================================================
void Cell::draw() const
{
	SDLDrawing::drawFilledRectangle(drawPos.x, drawPos.y,
		cellWidth - CELL_BLACK_BORDER, cellHeight - CELL_BLACK_BORDER, color);
}

// ================================================================================
// =================================== SETTERS ====================================
// ================================================================================
void Cell::setMazePos(int32_t x, int32_t y)
{
	mazePos.x = x;
	mazePos.y = y;
}

// ================================================================================
void Cell::setDrawPos(int32_t x, int32_t y)
{
	drawPos.x = x;
	drawPos.y = y;
}

// ================================================================================
void Cell::setDrawColor(const Color& c)
{
	color = c;
}

// ================================================================================
void Cell::setNeighbours(const std::vector<Cell*>& newNeighours)
{
	for (const auto& newNeighbour : newNeighours)
	{
		neighbours.push_back(newNeighbour);
	}
}

// ================================================================================
// ================================ STATIC GETTERS ================================
// ================================================================================
Cell* Cell::getStartCell()
{
	return startCell;
}

// ================================================================================
Cell* Cell::getDestCell()
{
	return destCell;
}

// ================================================================================
int32_t Cell::getBlockedCellsCount()
{
	return blockedCellsCount;
}

// ================================================================================
// =================================== GETTERS ====================================
// ================================================================================
Point Cell::getMazePos() const
{
	return mazePos;
}

// ================================================================================
bool Cell::getIsBlocked() const
{
	return isBlocked;
}

// ================================================================================
bool Cell::getIsVisited() const
{
	return isVisited;
}

// ================================================================================
const std::vector<Cell*>& Cell::getNeighbours()
{
	return neighbours;
}

// ================================================================================
// ================================================================================
// ================================================================================
void Cell::toggleStartFinish()
{
	if (isBlocked)
	{
		return;
	}

	if (!startCell && !destCell)
	{
		startCell = this;
	}
	else if (startCell && !destCell)
	{
		if (startCell == this)
		{
			startCell = nullptr;
		}
		else
		{
			destCell = this;
		}
	}
	else if (startCell && destCell)
	{
		if (destCell == this)
		{
			destCell = nullptr;
		}
	}
	else if (!startCell && destCell)
	{
		std::cerr << "Congratulations, you somehow managed to break the logic of the game."
			<< std::endl;
	}

	if (startCell == this)
	{
		color = colorStart;
	}
	else if (destCell == this)
	{
		color = colorFinish;
	}
	else
	{
		color = colorEmpty;
	}
}

// ================================================================================
void Cell::toggleBlocked()
{
	if (startCell && destCell &&
		((mazePos == startCell->mazePos) || (mazePos == destCell->mazePos)))
	{
		return;
	}

	isBlocked = !isBlocked;
	if (isBlocked)
	{
		color = colorBlocked;
		blockedCellsCount++;
	}
	else
	{
		color = colorEmpty;
		blockedCellsCount--;
	}
}

// ================================================================================
void Cell::toggleVisited(bool visited)
{
	if (startCell == this || destCell == this || isBlocked)
	{
		return;
	}

	isVisited = visited;
	if (isVisited)
	{
		color = colorVisited;
	}
	else
	{
		color = colorEmpty;
	}
}

// ================================================================================
void Cell::toggleValidPath(bool valid)
{
	if (startCell == this || destCell == this || isBlocked)
	{
		return;
	}

	isValidPath = valid;
	if (isValidPath)
	{
		color = colorValidPath;
	}
	else
	{
		color = colorEmpty;
	}
}

// ================================================================================
// ================================================================================
// ================================================================================
void Cell::restart()
{
	asd.localGoal = 100000;
	asd.globalGoal = 100000;
	asd.parent = nullptr;

	if (this == startCell || this == destCell || isBlocked)
	{
		return;
	}

	color = colorEmpty;
	isVisited = false;
	isValidPath = false;
}

// ================================================================================
void Cell::reset()
{
	asd.localGoal = 100000;
	asd.globalGoal = 100000;
	asd.parent = nullptr;

	mazePos.x = 0;
	mazePos.y = 0;
	drawPos.x = 0;
	drawPos.y = 0;
	color = colorEmpty;

	isBlocked = false;
	isVisited = false;
	isValidPath = false;
}

// ================================================================================
bool Cell::operator==(const Cell& other) const
{
	return this->mazePos == other.mazePos;
}

// ================================================================================
bool Cell::operator!=(const Cell& other) const
{
	return !operator==(other);
}