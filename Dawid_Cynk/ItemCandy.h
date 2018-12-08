#pragma once
#include "Item.h"
#include <SFML\Graphics.hpp>
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
 @class	ItemCandy

 @brief	Dziedziczy po klasie Item, obsluguje zachowanie cukierkow.
		Po kolizji gracza z ItemCandy gracz dostaje dodatkowy punkt.

 @author	Dawid Cynk
 @date		15.01.2018
 */

class ItemCandy : public ::Item
{
public:

	/**
	 @fn	public::ItemCandy();
	
	 @brief	Default constructor
	
	 */

	ItemCandy();

	/**
	 @fn	public::~ItemCandy();
	
	 @brief	Destructor
	
	 */

	~ItemCandy();
	
private:

	/**
	 @fn	void public::collisionReaction(Score *score);
	
	 @brief	Reakcja na kolizjê cukierka z ptakiem.
	
	 @param 	score	wskaznik do obiektu typu Score.
	 */

	void collisionReaction(Score *score);
	/** @brief	Tekstura cukierka */
	Texture ItemCandyTexture;
	/** @brief Wskaznik do obiektu  klasy Score */
	Score *score;

	/**
	 @fn	int public::loadTexture();
	
	 @brief	Wczytuje teksturê.
	
	 @return	Zwraca -1, gdy nie wczyta tekstury.
	 */

	int loadTexture();
};

