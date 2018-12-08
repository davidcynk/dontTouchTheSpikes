#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>
#include "MenuState.h"
#include "SplashState.h"
#include "PlayState.h"



using namespace std;
using namespace sf;

/**
 @class	MainState

 @brief	Stan gry, dziedziczy po klasie State.

 @author	Dawid Cynk
 @date	15.01.2018
 */

class MainState : public State
{
public:

	/**
	 @fn	MainState::MainState(String title, Vector2f screenRes);
	
	 @brief	Constructor
	
	 @param	title	 	Nazwa gry.
	 @param	screenRes	Rozmiar okna.
	 */

	MainState(String title, Vector2f screenRes);

	/**
	 @fn	MainState::~MainState();
	
	 @brief	Destructor

	 */

	~MainState();

	/**
	 @fn	void MainState::runGame();
	
	 @brief	Rozpoczyna grê.
	
	 */

	void runGame();
private:

	/**
	 @fn	void MainState::Init();
	
	 @brief	Tak jak w klasie State.
	

	 */

	void Init();

	/**
	 @fn	void MainState::HandleInput();
	
	@brief	Tak jak w klasie State.
	

	 */

	void HandleInput();

	/**
	 @fn	void MainState::Update();
	
	@brief	Tak jak w klasie State.
	
	 */

	void Update();

	/**
	 @fn	void MainState::Draw();
	
	@brief	Tak jak w klasie State.

	 */

	void Draw();

	/** @brief	Wskaznik do obiektu typu RenderWindow */
	RenderWindow *window;
	/** @brief	Rozmiar okna */
	Vector2f ScreenSize;
	/** @brief	Stan gry */
	GameStates state;
	/** @brief	Wskaznik do obiektu typu PlayState */
	PlayState *playState;
	/** @brief	Wskaznik do obiektu typu MenuState*/
	MenuState *menuState;
	/** @brief	Wskaznik do obiektu typu SplashState */
	SplashState *splashState;
	/** @brief	Ikona programu */
	Image icon;
};

