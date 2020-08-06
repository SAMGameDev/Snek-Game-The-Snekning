#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snek& snake)
{
	Respawn(rng, brd, snake);
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snek& snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetBoardWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetBoardHieght() - 1);
	Location newloc;

	do
	{
		newloc.x = xDist(rng);
		newloc.y = yDist(rng);
	} while (snake.isCollideWithGoal(newloc));
	{
		loc = newloc;
	}
}

void Goal::Draw(Board& brd)
{
	brd.DrawCell(loc, goalColor);
}

const Location& Goal::GetLocation() const
{
	return loc;
}
