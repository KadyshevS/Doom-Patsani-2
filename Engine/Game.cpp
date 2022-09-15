#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	for (int i = 0; i < gif2_frames; i++)
	{
		surfs2[i].Init("kud300px\\upload (" + std::to_string(i) + ").bmp");
	}

	sound.Play();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if(arrowInhibit) {}
		{
			frameIt *= 1.1;
			arrowInhibit = true;
		}
		arrowInhibit = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (arrowInhibit) {}
		{
			frameIt /= 1.1;
			arrowInhibit = true;
		}
		arrowInhibit = false;
	}

	const float curr_frameIt = frameIt * ft.Mark();
	if (int(frameTime1 + curr_frameIt) > gif2_frames - 1)
	{
		frameTime1 = 0.f;
	}

	frameTime1 += curr_frameIt;
}

void Game::ComposeFrame()
{
	gfx.DrawSpriteNoChroma(0, 0, surfs2[int(frameTime1)]);
}
