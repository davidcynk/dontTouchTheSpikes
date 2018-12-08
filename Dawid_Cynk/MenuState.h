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
 @class	MenuState

 @brief	Stan gry w menu, dziedziczy po klasie State.

 @author	Dawid Cynk
 @date		15.01.2018
 */

class MenuState : public State
{
public:

	/**
	 @fn	MenuState::MenuState(RenderWindow *window, GameStates *state);
	
	 @brief	Constructor
	
	 @param 	window	Okno gry
	 @param 	state 	Aktualny stan programu.
	 */

	MenuState(RenderWindow *window, GameStates *state);

	/**
	 @fn	MenuState::~MenuState();
	
	 @brief	Destructor

	 */

	~MenuState();

	/**
	 @fn	void MenuState::Init();
	
	 @brief	Tak jak w klasie State.

	 */

	void Init();

	/**
	 @fn	void MenuState::HandleInput();
	
	 @brief	Tak jak w klasie State.

	 */

	void HandleInput();

	/**
	 @fn	void MenuState::Update();
	
	 @brief	Tak jak w klasie State.

	 */

	void Update();

	/**
	 @fn	void MenuState::Draw();
	
	 @brief	Tak jak w klasie State.
	
	 */

	void Draw();
private:
	/** @brief	Wskaznik do obiektu typu RenderWindow */
	RenderWindow * window;
	/** @brief	Wskaznik do obiektu typu GameStates */
	GameStates *state;
	/** @brief	Wskaznik do obiektu typu Texture */
	Texture *tex;
	/** @brief	Wskaznik do obiektu typu Sprite */
	Sprite *background;
	/** @brief	Wskaznik do obiektu MenuOptions, uzywany by wyœwietliæ menu*/
	MenuOptions *options;
};

