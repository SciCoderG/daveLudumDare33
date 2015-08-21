#include "Game.h"
#include <iostream>

using namespace std;


Game::Game()
{
	m_bRunning = false;
}


Game::~Game()
{
}


bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded, create the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		// if the window creation succeeded create our renderer
		if (m_pWindow != 0)
		{
			cout << "window creation successfull.\n";

			// Create renderer
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0)
			{
				cout << "renderer creation successful.\n";
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			}
			else
			{
				cout << "renderer creation failed.\n";
				return false;
			}
		}
		else
		{
			cout << "window creation failed.\n";
			return false;
		}
	}
	else
	{
		cout << "SDL initialization failed.\n";
		return false; // SDL could not be initialized
	}
	cout << "SDL initialization success.\n";
	m_bRunning = true;
	return true;
}

void Game::update()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}

	SDL_RenderClear(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}