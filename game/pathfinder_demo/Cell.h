#ifndef CELL_H_
#define CELL_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/FrequentIncludes.h"

// Forward declarations

class Cell
{
public:
	static constexpr int32_t CELL_BLACK_BORDER = 3;

	struct AStarAlgorithmData
	{
		Cell* parent = nullptr;
		int32_t localGoal = 100000;
		double globalGoal = 100000;
	}asd;

public:
	static int32_t initStatic(int32_t w, int32_t h);
	int32_t init();
	void deinit();
	void handleEvent(const InputEvent& e);
	void update();
	void draw() const;

	void setMazePos(int32_t x, int32_t y);
	void setDrawPos(int32_t x, int32_t y);
	void setDrawColor(const Color& c);
	void setNeighbours(const std::vector<Cell*>& newNeighours);

	static Cell* getStartCell();
	static Cell* getDestCell();
	static int32_t getBlockedCellsCount();

	Point getMazePos() const;
	bool getIsBlocked() const;
	bool getIsVisited() const;
	const std::vector<Cell*>& getNeighbours();

	void toggleStartFinish();
	void toggleBlocked();
	void toggleVisited(bool visited);
	void toggleValidPath(bool valid);

	void restart();
	void reset();

	bool operator==(const Cell& other) const;
	bool operator!=(const Cell& other) const;

private:
	static Color colorEmpty;
	static Color colorStart;
	static Color colorFinish;
	static Color colorBlocked;
	static Color colorVisited;
	static Color colorValidPath;

	static Cell* startCell;
	static Cell* destCell;
	static int32_t blockedCellsCount;

	Point mazePos = Point::UNDEFINED;
	Point drawPos = Point::UNDEFINED;
	Color color = Colors::BLACK;

	bool isBlocked = false;
	bool isVisited = false;
	bool isValidPath = false;

	std::vector<Cell*> neighbours;
};

#endif // !CELL_H_