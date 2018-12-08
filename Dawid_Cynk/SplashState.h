#pragma once
#include "State.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "MenuOptions.h"

/**
 @namespace	sf

 @brief	.
 */

using namespace sf;

/**
 @class	SplashState

 @brief	Dziedziczy po klasie State, obsluguje ekran powitalny.

 @author	Dawid Cynk
 @date	15.01.2018
 */

class SplashState : public State
{
public:

	/**
	 @fn	SplashState::SplashState(RenderWindow *window, GameStates *state);
	
	 @brief	Constructor
	
	 @param 	window	wskaznik do obiektu typu RenderWindow.
	 @param 	state 	wskaznik do elementu typu GameStates.
	 */

	SplashState(RenderWindow *window, GameStates *state);

	/**
	 @fn	SplashState::~SplashState();
	
	 @brief	Destructor

	 */

	~SplashState();

	/**
	 @fn	void SplashState::Init();
	
	 @brief	Tak jak w klasie State.

	 */

	void Init();

	/**
	 @fn	void SplashState::HandleInput();
	
	 @brief	Tak jak w klasie State.
	
	 */

	void HandleInput();

	/**
	 @fn	void SplashState::Update();
	
	 @brief	Tak jak w klasie State.

	 */

	void Update();

	/**
	 @fn	void SplashState::Draw();
	
	 @brief	Tak jak w klasie State.

	 */

	void Draw();
private:
	/** @brief	Okno gry*/
	RenderWindow *window;
	/** @brief	Wykorzystywany do wyœwietlenia SplashState przez odpowiedni¹ iloœæ czasu, jeœli <0 to gra przechodzi do innego stanu */
	int counter;
	/** @brief	Wskaznik do obiektu typu GameStates */
	GameStates *state;
	/** @brief	Wskaznik do obiektu typu Texture */
	Texture *tex;
	/** @brief	Wskaznik do obiektu typu Sprite */
	Sprite *background;
	/** @brief	Wskaznik do obiektu MenuOptions */
	MenuOptions *options;
};

