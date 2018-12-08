#include "MainState.h"


MainState::MainState(String title, Vector2f ScreenSize)
{
	this->ScreenSize = ScreenSize;
	icon.loadFromFile("img/angry2.png");
	window = new RenderWindow(VideoMode(ScreenSize.x, ScreenSize.y), title);
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window->setFramerateLimit(60);
	window->setKeyRepeatEnabled(false);
	
	
}

MainState::~MainState()
{
	delete window;
}

void MainState::runGame()
{
	Init();
	while (window->isOpen())
	{
		HandleInput();
		Update();
		Draw();
	}
}

void MainState::Init()
{
	state = Splash;
	playState = new PlayState(window, &state);
	playState->Init();
	splashState = new SplashState(window, &state);
	splashState->Init();
	menuState = new MenuState(window, &state);
	menuState->Init();
}

void MainState::HandleInput()
{
	switch (state)
	{
	case MainState::Splash:
		splashState->HandleInput();
		break;
	case MainState::Menu:
		menuState->HandleInput();
		break;
	case MainState::Play:
		playState->HandleInput();
		break;
	default:
		break;
	}
}

void MainState::Update()
{
	switch (state)
	{
	case MainState::Splash:
		splashState->Update();
		break;
	case MainState::Menu:
		menuState->Update();
		break;
	case MainState::Play:
		if (playState->getGameFinal() == true)
		{
			delete playState;
			playState = new PlayState(window, &state);
			playState->Init();
		}
		playState->Update();
		break;
	default:
		break;
	}
}

void MainState::Draw()
{
	switch (state)
	{
	case MainState::Splash:
		splashState->Draw();
		break;
	case MainState::Menu:
		menuState->Draw();
		break;
	case MainState::Play:
		playState->Draw();
		break;
	default:
		break;
	}
	window->display();
	window->clear();
}
