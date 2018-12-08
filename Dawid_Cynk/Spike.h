#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include "DEFINITIONS.h"

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
 @class	Spike

 @brief	Klasa obs³ugujaca pojedyncza igle.

 @author	Dawid Cynk
 @date	15.01.2018
 */

class Spike : public ::Drawable
{
public:

	/**
	 @fn	public::Spike(bool isOnLeft, int Yposition);
	
	 @brief	Constructor

	 @param	isOnLeft 	prawda jesli igla znajduje sie na lewej scianie.
	 @param	Yposition	Pozycja w osi Y.
	 */

	Spike(bool isOnLeft, int Yposition);

	/**
	 @fn	public::~Spike();
	
	 @brief	Destructor
	
	 @author	Dejv
	 @date	15.01.2018
	 */

	~Spike();

	/**
	 @fn	void public::draw(RenderTarget& target, RenderStates state) const override;
	
	 @brief	Funkcja nadpisana z obiektu Drawable, uzywana do rysowania obiektu.
	
	 @param 	target	Target for the.
	 @param 			state 	The state.
	 */

	void draw(RenderTarget& target, RenderStates state) const override;

	/**
	 @fn	Sprite* public::getSpike();
	
	 @brief	Metoda zwracajaca wskaznik do obiektu typu Sprite.
	
	 */

	Sprite* getSpike();


private:
	/** @brief	Tekstura igly */
	Texture spikeTexture;
	/** @brief	Pozycja ilgy */
	Vector2f position;

	/**
	 @fn	int public::loadTexture();
	
	 @brief	Metoda wczytujaca teksture
	
	 @return jesli blad podczas wczytywania, zwraca -1.
	 */

	int loadTexture();
	/** @brief	Obiekt typu Sprite*/
	Sprite spike;
};

