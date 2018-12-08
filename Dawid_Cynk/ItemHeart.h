#pragma once
#include "Item.h"
#include <SFML\Graphics.hpp>
#include "Bird.h"
#include "SpikeManager.h"

/**
 @class	ItemHeart

 @brief	Dziedziczy po klasie Item, obs�uguje zachowanie serduszek.
		Po kolizji gracza z serduszkiem dostajemy dodatkowe �ycie.

 @author	Dejv
 @date		15.01.2018
 */

class ItemHeart : public ::Item
{
public:

	/**
	 @fn	public::ItemHeart(Score *score);
	
	 @brief	Constructor
	
	 @param 	score	Je�li nie pusty, score.
	 */

	ItemHeart(Score *score);

	/**
	 @fn	public::~ItemHeart();
	
	 @brief	Destructor
	
	 */

	~ItemHeart();

	/**
	 @fn	Vector2i public::randomItemPosition(Score *score);
	
	 @brief	Losuje pozycje serduszka.

	 @param 	score	jesli nie pusty, score.
	
	 @return	zwraca pozycj� cukierka(wektor X i Y).
	 */

	Vector2i randomItemPosition(Score *score);
	
private:

	/**
	 @fn	void public::collisionReaction(Score *score);
	
	 @brief	Reakcja na kolizj� z ptakiem.
	
	 @param 	score	je�li nie puste, score.
	 */

	void collisionReaction(Score *score);
	/** @brief	Tekstura serduszka */
	Texture ItemHeartTexture;

	/**
	 @fn	int public::loadTexture();
	
	 @brief	Wczytuje tekstur� serduszka.

	 @return	Zwraca -1, gdy nie wczyta tekstury, w przeciwnym razie ustawia tekstur�.
	 */

	int loadTexture();

	

};

