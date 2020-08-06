#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	: gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < hieght);

	int off_x = x;
	int off_y = y;

	gfx.DrawRectDim(loc.x * cellDimension + off_x + 1, loc.y * cellDimension + off_y + 1, cellDimension - 1 * 2, cellDimension - 1 * 2, c);
}

void Board::DrawBorder()
{
	const int top = y - boarderWidth - boarderPadding;
	const int left = x - boarderWidth - boarderPadding;
	const int bottom = top + (boarderWidth + boarderPadding) * 2 + hieght * cellDimension;
	const int right = left + (boarderWidth + boarderPadding) * 2 + width * cellDimension;

	//top
	gfx.DrawRect(left, top, right, top + boarderWidth, boaderColor);

	//left
	gfx.DrawRect(left, top + boarderWidth, left + boarderWidth, bottom - boarderWidth, boaderColor);

	//right
	gfx.DrawRect(right - boarderWidth, top + boarderWidth, right, bottom - boarderWidth, boaderColor);

	//bottom
	gfx.DrawRect(left, bottom - boarderWidth, right, bottom, boaderColor);
}

int Board::GetBoardWidth() const
{
	return width;
}

int Board::GetBoardHieght() const
{
	return hieght;
}

bool Board::isInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width &&
		   loc.y >= 0 && loc.y < hieght;
}
