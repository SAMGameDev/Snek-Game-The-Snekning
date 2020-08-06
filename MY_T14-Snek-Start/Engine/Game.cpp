#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	: wnd(wnd),
	  gfx(wnd),
	  board(gfx),
	  rng(std::random_device()()),
	  snake({ 2, 2 }),
	  goal(rng, board, snake)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		isStarted = true;
	}

	if (isStarted)
	{

		if (!isDead)
		{

			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				delta_Loc = { 0, -1 };
			}
			if (wnd.kbd.KeyIsPressed(VK_DOWN))
			{
				delta_Loc = { 0, 1 };
			}
			if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				delta_Loc = { 1, 0 };
			}
			if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				delta_Loc = { -1, 0 };
			}
			++moveCounter;

			if (moveCounter >= movePeriod)
			{
				moveCounter = 0;

				const Location next = snake.GetHeadLocation(delta_Loc);

				if (!board.isInsideBoard(next) || snake.isCollideWithItSelf(next))
				{
					isDead = true;
				}
				else
				{
					snake.MoveBy(delta_Loc);


					const bool isEaten = next == goal.GetLocation();
					if (isEaten)
					{
						snake.Grow();
					}
					if (isEaten)
					{
						goal.Respawn(rng, board, snake);
						if (movePeriod > 4)
						{
							--movePeriod;
						}
						else
						{
							return;
						}
					}
				}
			}
		}
	}
}

void Game::ComposeFrame()
{
	if (isStarted)
	{
		if (!isDead)
		{
			snake.Draw(board);
			goal.Draw(board);
		}
		else
		{
			spriteCode.DrawGameOver(350, 250, gfx);
		}

		board.DrawBorder();
	}
	else
	{
		spriteCode.DrawTitle(280, 200, gfx);
	}
}
