#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include <random>
#include "Snek.h"
#include "Goal.h"
#include "SpriteCodex.h"


class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();

private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;

	/********************************/
	/*  User Variables              */
	Board board;
	std::mt19937 rng;
	Snek snake;
	Goal goal;
	Location delta_Loc = { 1, 0 };
	int movePeriod = 10;
	int moveCounter = 0;
	bool isDead = false;
	bool isStarted = false;
	SpriteCodex spriteCode;
	/********************************/
};