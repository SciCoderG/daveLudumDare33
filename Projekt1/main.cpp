#include <SDL.h>

#include "Game.h"

Game* g_pGame = 0;

int main(int argc, char* args[])
{
	g_pGame = new Game();

	g_pGame->init("jo", 100, 100, 640, 480, 0);

	while (g_pGame->running())
	{
		g_pGame->update();
	}
	
	g_pGame->clean();

	return 0;
}


