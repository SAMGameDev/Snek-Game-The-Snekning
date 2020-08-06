#include "Snek.h"
#include <assert.h>

Snek::Snek(const Location& loc)
{
	const int maxbodycolors = 4;
	constexpr Color bodyColors[maxbodycolors]{
		{ 10, 100, 32 },
		{ 10, 130, 48 },
		{ 18, 160, 48 },
		{ 10, 130, 48 },
	};

	for (int i = 0; i < maxSegments; ++i)
	{
		segments[i].initBody(bodyColors[i % maxbodycolors]);
	}

	segments[0].InitHead(loc);
}

void Snek::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

Location Snek::GetHeadLocation(const Location& headLocNow) const
{
	Location l = segments[0].GetLocation();
	l.Add(headLocNow);
	return l;
}

void Snek::Grow()
{
	if (nSegments < maxSegments)
	{
		nSegments++;
	}
}

void Snek::Draw(Board& brd)
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].Draw(brd);
	}
}

bool Snek::isCollideWithItSelf(const Location& isInsameTile) const
{
	for (int i = 0; i < nSegments - 1; ++i)
	{
		if (segments[i].GetLocation() == isInsameTile)
		{
			return true;
		}
	}
	return false;
}

bool Snek::isCollideWithGoal(const Location& goalLoc) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		if (segments[i].GetLocation() == goalLoc)
		{
			return true;
		}
	}
	return false;
}

void Snek::Segment::InitHead(const Location& spawnLoc)
{
	loc = spawnLoc;
	c = Headcolor;
}

void Snek::Segment::initBody(Color bColor)
{
	c = bColor;
}

void Snek::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snek::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snek::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

Location Snek::Segment::GetLocation() const
{
	return loc;
}
