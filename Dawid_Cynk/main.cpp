#pragma once
#include "MainState.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>


int main()
{
	MainState game{ "Don't touch the spikes", sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT) };
	game.runGame();
	return 0;
}