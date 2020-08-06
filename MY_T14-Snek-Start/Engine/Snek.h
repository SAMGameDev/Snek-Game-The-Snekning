#pragma once
#include "Board.h"
class Snek
{
public:
	class Segment
	{
	public:
		void InitHead(const Location& spawnLoc);
		void initBody(Color bColor);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
		Location GetLocation() const;

	private:
		Location loc;
		Color c;
	};

public:
	Snek(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetHeadLocation(const Location& headLocNow) const;
	void Grow();
	void Draw(Board& brd);
	bool isCollideWithItSelf(const Location& isInsameTile) const;
	bool isCollideWithGoal(const Location& goalLoc) const;

private:
	static constexpr Color Headcolor = Colors::Red;
	static constexpr int maxSegments = 100;
	Segment segments[maxSegments];
	int nSegments = 1;
};
