#pragma once
#include "Colors.h"
#include "RectM.h"
#include <string>

class Surface
{
	Color* pPixels = nullptr;
	int width, height;
	int nPixels;

public:
	Surface() = default;
	Surface(const std::string& filename)
	{
		Init(filename);
	}
	Surface(int Width, int Height)
	{
		Init(Width, Height);
	}
	Surface(const Surface& oth)
	{
		Init(oth);
	}

	void Init(const std::string& filename);
	void Init(int Width, int Height);
	void Init(const Surface& oth);

	Surface& operator = (const Surface& oth);
	void PutPixel(int X, int Y, Color Color);
	Color GetPixel(int X, int Y) const;
	int GetWidth() const;
	int GetHeight() const;

	~Surface();
};