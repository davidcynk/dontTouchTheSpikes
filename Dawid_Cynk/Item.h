#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Spike.h"
#include "SpikeManager.h"
#include "Score.h"

/**
 @namespace	std

 @brief	.
 */

using namespace std;

/**
 @namespace	sf

 @brief	.
 */

using namespace sf;

/**
 @class	Item

 @brief	G³owna klasa Itemu, po ktorej dziedzicza konkretne Itemy.

 @author	Dawid Cynk
 @date		15.01.2018
 */

class Item : public ::Drawable
{
public:

	/**
	 @fn	public::Item();
	
	 @brief	Default constructor
	
	 */

	Item();

	/**
	 @fn	public::~Item();
	
	 @brief	Destructor

	 */

	~Item();

	/**
	 @fn	void public::setPosition(Vector2i pos);
	
	 @brief	Metoda zmieniajaca pozycje itemu.
	
	 @param	pos	 pozycja przekazana jako wektor.
	 */

	void setPosition(Vector2i pos);

	/**
	 @fn	bool public::checkCollision(Bird* bird, Score * score);
	
	 @brief	Sprawdza kolizjê ptaka z Itemem.
	
	 @param	bird wskaznik do obiektu typu Bird.
	 @param	score wskaznik do obiektu typu Score.
	
	 @return	Zwraca prawdê, gdy wystêpuje kolizja.
	 */

	bool checkCollision(Bird* bird, Score * score);

	/**
	 @fn	Sprite public::*getSpriteItem();
	
	 @brief		Metoda zwracajaca wskaznik do obiektu typu SpriteItem.
	
	 @return	Zwraca wskaznik do spriteItem.
	 */

	Sprite *getSpriteItem();

	/**
	 @fn	Vector2i public::randomItemPosition();
	
	 @brief	Metoda losujaca pozycje Itemu.

	 @return	Zwraca wektor, czyli wspo³rzêdne Itemu.
	 */

	Vector2i randomItemPosition();

protected:
	/** @brief	wskaznik do obiektu typu SpikeManager */
	SpikeManager *spikes;
	/** @brief	Sprite Itemu */
	Sprite spriteItem;
	/** @brief	Pozycja Itemu */
	Vector2i position;

	/**
	 @fn	void public::draw(RenderTarget & target, RenderStates state) const override;
	
	 @brief	Funkcja nadpisana z obiektu Drawable, u¿ywana do rysowania obiektu.
	
	 @param 	target	Target for the.
	 @param 	state 	The state.
	 */

	void draw(RenderTarget & target, RenderStates state) const override;

	/**
	 @fn	virtual void public::collisionReaction(Score *score) = 0;
	
	 @brief	Metoda obslugujaca reakcje na kolizje.
	
	 @param 	score	Wskaznik do obiektu typu Score.
	 */

	virtual void collisionReaction(Score *score) = 0;


};

