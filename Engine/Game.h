#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Surface.h"
#include "RectM.h"
#include "FrameTimer.h"
#include "SoundEffect.h"
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	FrameTimer ft;
	float frameTime1 = 0.f;
	float frameIt = 0.25f * 60.f;

	bool arrowInhibit = false;

	static const short gif2_frames = 50;

	Surface surfs2[gif2_frames];

	Sound sound = Sound(L"Sounds\\incelcore.wav");
	/********************************/
};