#pragma once
#include "Snek.h"
#include "Location.h"
#include "Board.h"
#include <random>

class Goal
{
public:
	Goal(std::mt19937& rng, const Board& brd, const Snek& snake);
	void Respawn(std::mt19937& rng, const Board& brd, const Snek& snake);
	void Draw(Board& brd);
	const Location& GetLocation() const;

private:
	static constexpr Color goalColor = Colors::Magenta;
	Location loc;
};
