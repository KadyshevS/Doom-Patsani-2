#include "RectM.h"

RectM::RectM(const int Top, const int Bottom, const int Left, const int Right)
	:
	top(Top),
	bottom(Bottom),
	left(Left),
	right(Right)
{}
RectM::RectM(const Vec2& TopLeft, const int Width, const int Height)
	:
	top(TopLeft.y),
	bottom(TopLeft.y+Height),
	left(TopLeft.x),
	right(TopLeft.x+Width)
{}
RectM::RectM(const Vec2& TopLeft, const Vec2& BottomRight)
	:
	top(TopLeft.y),
	bottom(BottomRight.y),
	left(TopLeft.x),
	right(BottomRight.x)
{}

int RectM::GetWidth() const
{
	return right - left;
}
int RectM::GetHeight() const
{
	return bottom - top;
}

bool RectM::IsOverlappingWith(const RectM& other)
{
	return	(top <= other.bottom && left <= other.right) ||
			(top <= other.bottom && right >= other.left) ||
			(bottom >= other.top && left <= other.right) ||
			(bottom >= other.top && right >= other.left)  ;
}
