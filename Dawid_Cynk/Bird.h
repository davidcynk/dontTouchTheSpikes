#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include "DEFINITIONS.h"
#include "Score.h"




using namespace std;
using namespace sf;

/**
 @class	Bird

 @brief	Klasa obsluguje zachowanie i glowne cechy ptaka.

 @author	Dawid Cynk
 @date	11.01.2018
 */

class Bird : public ::Drawable
{
public:

	/**
	 @fn	public::Bird(Vector2f posiotion);
	
	 @brief	Constructor
	
	 @param	posiotion	Pozycja ptaka.
	 */

	Bird(Vector2f posiotion);

	/**
	 @fn	public::~Bird();
	
	 @brief	Destructor
	
	 */

	~Bird();

	/**
	 @fn	void public::draw(RenderTarget& target, RenderStates state) const override;
	
	 @brief	Funkcja nadpisana z obiektu Drawable, u�ywana do rysowania obiektu.
	
	 @param 	target	
	 @param 	state 	
	 */

	void draw(RenderTarget& target, RenderStates state) const override;

	/**
	 @fn	void public::updateMove();
	
	 @brief	Metoda obsluguj�ca ruch ptaka.
	
	 */

	void updateMove();

	/**
	 @fn	bool public::getIsBounced();

	
	 @return	Metoda zwraca zmienn� isBounced;
	 */

	bool getIsBounced();

	/**
	 @fn	void public::setIsBounced(bool);
	
	 @brief	Metoda edytuj�ca zmienn� isBounced;
	
	 */

	void setIsBounced(bool);

	/**
	 @fn	void public::jump();
	
	 @brief	Metoda obs�uguj�ca podskakiwanie ptaszka.
	
	 */

	void jump();

	/**
	 @fn	Sprite public::*getSprite();
	
	 @brief	Metoda zwraca wskaznik do obiektu typu Sprite.

	 */

	Sprite *getSprite();

	/**
	 @fn	Vector2f public::getPosition();
	
	 @brief	Metoda zwracaj�ca pozycj� ptaka.

	 */

	Vector2f getPosition();

	/**
	 @fn	void public::killBird(Score *score);
	
	 @brief	Metoda obs�uguj�ca zachowanie ptaka po zgini�ciu.

	 @param score wskaznik do obiektu typu Score.
	 */

	void killBird(Score *score);

	/**
	 @fn	void public::setVelocity(Vector2f velocity);
	
	 @brief Metoda obs�uguj�ca zmian� pr�dko�ci ptaka.

	
	 @param	velocity	The velocity.
	 */

	void setVelocity(Vector2f velocity);

private:
	/** @brief	Tekstura ptaka */
	Texture BirdTexture;
	/** @brief	Sprite ptaka */
	Sprite birdSprite;
	/** @brief	Wektor pozycji ptaka */
	Vector2f position;
	/** @brief	Wektor pr�dko�ci ptaka */
	Vector2f velocity;

	/**
	 @fn	int public::loadTexture();
	
	 @brief	�aduje teksture ptaka.
	
	 @return	Zwraca -1, gdy nie uda si� wczyta� tekstury.
	 */

	int loadTexture();
	/** @brief Je�li ptak odbija si� od �ciany przyjmuje warto�� true */
	bool isBounced;
};

