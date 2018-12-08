#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include "DEFINITIONS.h"
#include "ItemHeart.h"
#include "ItemCandy.h"
#include "ItemPause.h"
#include "Score.h"
#include "Sounds.h"


using namespace std;
using namespace sf;

/**
 @class	PlayState

 @brief	Dziedziczy po State, obsluguje stan gry podczas rozgrywki.

 @author	Dawid Cynk
 @date	11.01.2018
 */

class PlayState : public State
{
public:

	/**
	 @fn	PlayState::PlayState(RenderWindow *window, GameStates * state);
	
	 @brief	Constructor
	
	 @param 	window	okno programu.
	 @param 	state 	aktualny stan programu.
	 */

	PlayState(RenderWindow *window, GameStates * state);

	/**
	 @fn	PlayState::~PlayState();
	
	 @brief	Destructor
	
	 */

	~PlayState();

	/**
	 @fn	void PlayState::Init();
	
	 @brief	Tak jak w klasie State
	
	 */

	void Init();

	/**
	 @fn	void PlayState::HandleInput();
	
	 @brief	Tak jak w klasie State
	 
	 */

	void HandleInput();

	/**
	 @fn	void PlayState::Update();
	
	 @brief	Tak jak w klasie State
	
	 */

	void Update();

	/**
	 @fn	void PlayState::Draw();
	
	 @brief	Tak jak w klasie State
	
	 */

	void Draw();

	/**
	 @fn	bool PlayState::getGameFinal();
	
	 @brief	Metoda zwracaj�ca "bool isGameFinal"
	
	 @return	zwraca prawd� je�li gra sko�czona.
	 */

	bool getGameFinal();

	/**
	 @fn	Score PlayState::*getScore();
	
	 @return	Metoda zwraca wskaznik do obiektu typu Score.
	 */
	Score *getScore();
	
private:
	/** @brief	Wskaznik do obiektu typu RenderWindow */
	RenderWindow *window;
	/** @brief	Wskaznik do obiektu typu GameStates */
	GameStates *state;
	/** @brief	Tekstura t�a */
	Texture backgroundTexture;
	/** @brief	Sprite t�a */
	Sprite backgroundSprite;
	/** @brief	Rozmiar okna */
	Vector2f ScreenSize;
	/** @brief	wskaznik do obiektu klasy Bird */
	Bird *bird;
	/** @brief	wskaznik do obiektu klasy SpikeManager */
	SpikeManager *spikes;
	/** @brief	wskaznik do obiektu klasy IteamHeart */
	ItemHeart *heart;
	/** @brief	wskaznik do obiektu klasy ItemCandy */
	ItemCandy *candy;
	/** @brief	wskaznik do obiektu klasy ItemPause */
	ItemPause *pause;
	/** @brief	wskaznik do obiektu klasy Score */
	Score *score;
	/** @brief	wskaznik do obiektu klasy Sounds */
	Sounds *sound;
	/** @brief	Prawda, je�li gra jest uruchomiona, nieprawda, je�li nie */
	bool isGameStarted;
	/**
	 @fn	int PlayState::setBackground();
	
	 @brief	Metoda ustawiajaca aktualne tlo.
	
	 */
	int setBackground();
	/** @brief	Prawda, je�li gra jest zako�czona, nieprawda, je�li nie*/
	bool isGameOver;
	/** @brief	Prawda, je�li gra jest zako�czona, nieprawda, je�li nie*/
	bool isGameFinal;
	/** @brief	Prawda, je�li gra jest zapauzowana, nieprawda, je�li nie*/
	bool isPaused;
};

