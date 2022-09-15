#pragma once
#include "Vec2.h"

class RectM
{
public:
	int top, bottom, left, right;

public:
	RectM(const int Top, const int Bottom, const int Left, const int Right);
	RectM(const Vec2& TopLeft, const int Width, const int Height);
	RectM(const Vec2& TopLeft, const Vec2& BottomRight);

	int GetWidth() const;
	int GetHeight() const;
	bool IsOverlappingWith(const RectM& other);
};