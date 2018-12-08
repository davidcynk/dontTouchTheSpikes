#include "MenuState.h"


MenuState::MenuState(RenderWindow * window, GameStates * state)
{
	this->window = window;
	this->state = state;
	tex = new Texture();
	tex->loadFromFile("img/tloMenu.png");
	background = new Sprite(*tex);

}

MenuState::~MenuState()
{
	delete background;
	delete options;
}

void MenuState::Init()
{
	options = new MenuOptions(100);
	options->addOption(Vector2f(100, 100), "Graj", 0);
	options->addOption(Vector2f(100, 200), "Wyjdz", 2);
}

void MenuState::HandleInput()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == Event::Closed)
			window->close();
		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Escape)
			{
				window->close();
			}
			if (event.key.code == Keyboard::Space || event.key.code == Keyboard::Return)
			{
				int val = options->getValue();
				switch (val) {
				case 0:
					*state = Play;
					break;
				case 1:
					break;
				case 2:
					window->close();
					break;
				}
			}
		}
		options->handleInput(&event);
	}
}

void MenuState::Update()
{
}

void MenuState::Draw()
{
	window->draw(*background);
	options->draw(window);
}
