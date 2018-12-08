#include "SplashState.h"


SplashState::SplashState(RenderWindow * window, GameStates * state)
{
	this->window = window;
	this->state = state;
	this->counter = SPLASH_TIME * FPS_LIMIT;
	tex = new Texture();
	tex->loadFromFile("img/tloSplash.png");
	background = new Sprite(*tex);
}

SplashState::~SplashState()
{
	delete options;
}

void SplashState::Init()
{
	options = new MenuOptions(100);
}

void SplashState::HandleInput()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == Event::Closed)
			window->close();
		if (event.type == Event::KeyPressed)
		{

		}
	}
}

void SplashState::Update()
{
	counter--;
	if (counter < 0) {
		*state = Menu;
	}
}

void SplashState::Draw()
{
	window->draw(*background);
	options->draw(window);
}
