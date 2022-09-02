// Corresponding header
#include "game/Game.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "game/pathfinder_demo/Pathfinder.h"
#include "game/ui/hud/HUD.h"
#include "game/ui/menus/BottomMenu.h"

// ================================================================================
int32_t Game::init()
{
	pathfinder = new Pathfinder;
	hud = new HUD;
	bottomMenu = new BottomMenu;

	hud->init();
	bottomMenu->init(true);

	return EXIT_SUCCESS;
}

// ================================================================================
void Game::deinit()
{
	bottomMenu->deinit();
	hud->deinit();
	pathfinder->deinit();

	delete bottomMenu;
	delete hud;
	delete pathfinder;
	pathfinder = nullptr;
	hud = nullptr;
	bottomMenu = nullptr;
}

// ================================================================================
void Game::handleEvent(const InputEvent& e)
{
	if(e.type != EventType::MOUSE_BUTTONDOWN || e.type != EventType::MOUSE_BUTTONUP)

	if (e.type == EventType::MOUSE_BUTTONDOWN)
		Audio::playSound(SoundId::MC_PRESS, 0);

	else if (e.type == EventType::MOUSE_BUTTONUP)
		Audio::playSound(SoundId::MC_RELEASE, 0);

	pathfinder->handleEvent(e);
	bottomMenu->handleEvent(e);
}

// ================================================================================
void Game::update()
{
	Pathfinder::MazeData md = pathfinder->getMazeData();

	Point startPos = Point::UNDEFINED;
	Point destPos = Point::UNDEFINED;
	if(md.startCell)
		startPos = md.startCell->getMazePos();
	if(md.destCell)
		destPos = md.destCell->getMazePos();

	hud->update(md.cellsCountX, md.cellsCountY, startPos, destPos,
		md.blockedCellsCount, md.pathLength);

	switch(bottomMenu->getClickedButtonId())
	{
	case ButtonId::RESET:
		pathfinder->reset();
		break;

	default:
		break;
	}

	bottomMenu->update();

	if (pathfinder->getIsInitialized())
	{
		return;
	}

	pathfinder->init(100, 50);
}

// ================================================================================
void Game::draw() const
{
	pathfinder->draw();
	hud->draw();
	bottomMenu->draw();
}