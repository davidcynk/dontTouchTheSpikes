#pragma once
#include "Item.h"
#include <SFML\Graphics.hpp>
#include "Bird.h"
#include "SpikeManager.h"

/**
 @class	ItemPause

 @brief	Dziedziczy po klasie Item, obsluguje zachowanie pauzy.
		Po kolizji gracza z obiektem klasy ItemPause otrzymujemy mozliwosc zatrzymania gry.

 @author	Dawid Cynk
 @date		11.01.2018
 */

class ItemPause: public :: Item
{
public:

	/**
	 @fn	public::ItemPause(Score *score);
	
	 @brief	Constructor
	
	 @param		score	Wskaznik od obiektu typu Score.
	 */

	ItemPause(Score *score);

	/**
	 @fn	public::~ItemPause();
	
	 @brief	Destructor
	
	 */

	~ItemPause();

	/**
	 @fn	Vector2i public::randomItemPosition(Score *score);
	
	  @brief	Losuje pozycje pauzy.

	 @param 	score	wskaznik do obiektu typu Score.
	
	 @return	zwraca pozycjê pauzy(wektor X i Y).
	 */

	Vector2i randomItemPosition(Score *score);
private:

	/**
	 @fn	void public::collisionReaction(Score *score);
	
	 @brief	Reakcja na kolizjê pauzy z ptakiem.
	
	 @param		score	wskaznik do obiektu typu Score.
	 */

	void collisionReaction(Score *score);
	/** @brief	Tekstura pauzy */
	Texture ItemPauseTexture;

	/**
	 @fn	int public::loadTexture();
	
	@brief	Wczytuje teksturê serduszka.

	 @return	Zwraca -1, gdy nie wczyta tekstury.
	 */

	int loadTexture();
};

