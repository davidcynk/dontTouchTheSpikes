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
	
	 @brief	Funkcja nadpisana z obiektu Drawable, u¿ywana do rysowania obiektu.
	
	 @param 	target	
	 @param 	state 	
	 */

	void draw(RenderTarget& target, RenderStates state) const override;

	/**
	 @fn	void public::updateMove();
	
	 @brief	Metoda obsluguj¹ca ruch ptaka.
	
	 */

	void updateMove();

	/**
	 @fn	bool public::getIsBounced();

	
	 @return	Metoda zwraca zmienn¹ isBounced;
	 */

	bool getIsBounced();

	/**
	 @fn	void public::setIsBounced(bool);
	
	 @brief	Metoda edytuj¹ca zmienn¹ isBounced;
	
	 */

	void setIsBounced(bool);

	/**
	 @fn	void public::jump();
	
	 @brief	Metoda obs³uguj¹ca podskakiwanie ptaszka.
	
	 */

	void jump();

	/**
	 @fn	Sprite public::*getSprite();
	
	 @brief	Metoda zwraca wskaznik do obiektu typu Sprite.

	 */

	Sprite *getSprite();

	/**
	 @fn	Vector2f public::getPosition();
	
	 @brief	Metoda zwracaj¹ca pozycjê ptaka.

	 */

	Vector2f getPosition();

	/**
	 @fn	void public::killBird(Score *score);
	
	 @brief	Metoda obs³uguj¹ca zachowanie ptaka po zginiêciu.

	 @param score wskaznik do obiektu typu Score.
	 */

	void killBird(Score *score);

	/**
	 @fn	void public::setVelocity(Vector2f velocity);
	
	 @brief Metoda obs³uguj¹ca zmianê prêdkoœci ptaka.

	
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
	/** @brief	Wektor prêdkoœci ptaka */
	Vector2f velocity;

	/**
	 @fn	int public::loadTexture();
	
	 @brief	£aduje teksture ptaka.
	
	 @return	Zwraca -1, gdy nie uda siê wczytaæ tekstury.
	 */

	int loadTexture();
	/** @brief Jeœli ptak odbija siê od œciany przyjmuje wartoœæ true */
	bool isBounced;
};

