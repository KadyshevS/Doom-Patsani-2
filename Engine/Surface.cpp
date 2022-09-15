#include "Surface.h"
#include "ChiliWin.h"
#include <cassert>
#include <fstream>

void Surface::Init(const std::string& filename)
{
	std::ifstream in(filename, std::ios::binary);
	assert(in);

	BITMAPFILEHEADER bmFileHeader;
	in.read(reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader));

	BITMAPINFOHEADER bmInfoHeader;
	in.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));

	assert(bmInfoHeader.biBitCount == 24 || bmInfoHeader.biBitCount == 32);
	assert(bmInfoHeader.biCompression == BI_RGB);

	const bool is32 = bmInfoHeader.biBitCount == 32;

	width = bmInfoHeader.biWidth;

	int yStart, yEnd, dy;

	if (bmInfoHeader.biHeight < 0)
	{
		height = -bmInfoHeader.biHeight;
		yStart = 0;
		yEnd = height;
		dy = 1;
	}
	else
	{
		height = bmInfoHeader.biHeight;
		yStart = height - 1;
		yEnd = -1;
		dy = -1;
	}

	pPixels = new Color[width*height];
	in.seekg(bmFileHeader.bfOffBits);
	const int padding = (4 - (width * 3) % 4) % 4;

	for (int y = yStart; y != yEnd; y += dy)
	{
		for (int x = 0; x < width; x++)
		{
			PutPixel(x, y, Color(in.get(), in.get(), in.get()));
			if (is32)
			{
				in.seekg(1, std::ios::cur);
			}
		}
		if (!is32)
		{
			in.seekg(padding, std::ios::cur);
		}
	}
}
void Surface::Init(int Width, int Height)
{
	width = Width;
	height = Height;
	nPixels = Width * Height;
	pPixels = new Color[Width*Height];
}
void Surface::Init(const Surface& oth)
{
	Init(oth.width, oth.height);
	for (int i = 0; i < nPixels; i++)
	{
		pPixels[i] = oth.pPixels[i];
	}
}

Surface& Surface::operator=(const Surface& oth)
{
	width = oth.width;
	height = oth.height;

	delete[] pPixels;
	pPixels = new Color[width*height];

	return *this;
}

void Surface::PutPixel(int X, int Y, Color Color)
{
	assert(X >= 0);
	assert(X < width);
	assert(Y >= 0);
	assert(Y < height);
	pPixels[Y*width + X] = Color;
}

Color Surface::GetPixel(int X, int Y) const
{
	assert(X >= 0);
	assert(X < width);
	assert(Y >= 0);
	assert(Y < height);
	return pPixels[Y*width + X];
}
int Surface::GetWidth() const
{
	return width;
}
int Surface::GetHeight() const
{
	return height;
}

Surface::~Surface()
{
	delete[] pPixels;
	pPixels = nullptr;
}
