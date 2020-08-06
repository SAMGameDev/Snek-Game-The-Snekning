#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	void DrawBorder();
	int GetBoardWidth() const;
	int GetBoardHieght() const;
	bool isInsideBoard(const Location& loc) const;

private:
	static constexpr Color boaderColor = Colors::Cyan;
	static constexpr int cellDimension = 20;
	static constexpr int width = 38;
	static constexpr int hieght = 28;
	static constexpr int boarderWidth = 4;
	static constexpr int boarderPadding = 2;
	static constexpr int x = 20;
	static constexpr int y = 20;
	Graphics& gfx;
};
