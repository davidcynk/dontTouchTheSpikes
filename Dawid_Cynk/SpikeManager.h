#pragma once
#include "Spike.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Bird.h"
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
 @class	SpikeManager

 @brief Menadzer igiel, zawiera metody obs�uguj�ce zachowanie igiel.

 @author	Dawid Cynk
 @date	15.01.2018
 */

class SpikeManager 
{
public:

	/**
	 @fn	SpikeManager::SpikeManager(Texture *texture);
	
	 @brief	Constructor
	
	 @param texture   wskaznik do obiektu typu Texture.
	 */

	SpikeManager(Texture *texture);

	/**
	 @fn	SpikeManager::~SpikeManager();
	
	 @brief	Destructor
	
	
	 */

	~SpikeManager();

	/**
	 @fn	void SpikeManager::resetLeftSpikes(int points);
	
	 @brief	Resetuje igly znajdujace si� na lewej scianie.
	
	 @param	points - aktualna liczba punkt�w.
	 */

	void resetLeftSpikes(int points);

	/**
	 @fn	void SpikeManager::resetRightSpikes(int points);
	
	 @brief	Resetuje igly znajdujace si� na prawej scianie.
	
	 
	 @param	points - aktualna liczba punkt�w.
	 */

	void resetRightSpikes(int points);

	/**
	 @fn	int SpikeManager::createBottomTopSpikes();
	
	 @brief	Tworzy ig�y na dolnej i g�rnej scianie, wczytuje teksture.
	
	
	
	 @return	Zwraca -1, gdy tekstura nie zostanie wczytana.
	 */

	int createBottomTopSpikes();

	/**
	 @fn	bool SpikeManager::checkCollision(Bird *bird, Score *score);
	
	 @brief	Sprawdza kolizje ptaszka z iglami.
	
	 @param 	bird    wskaznik do obiektyu typu Bird.
	
	 @return	Zwraca prawd� gdy kolizja wystepuje.
	 */

	bool checkCollision(Bird *bird);

	/**
	 @fn	bool SpikeManager::checkCollisionTopBottom(Bird *bird);
	
	 @brief	Sprawdza kolizje z dolna i g�rna �ciana.
	
	 @param		bird	wskaznik do obiektyu typu Bird.
	
	 @return	Zwraca prawde gdy kolizja wystepuje.
	 */

	bool checkCollisionTopBottom(Bird *bird);

	/**
	 @fn	void SpikeManager::draw(RenderWindow &window) const;
	
	 @brief	Rysuje wszystkie igly na ekranie.
	
	 @param Okno gry.
	 */

	void draw(RenderWindow &window) const;
	

private:
	/** @brief	Ig�y na lewej �cianie */
	vector<Spike> leftSpikes;
	/** @brief	Ig�y na prawej �cianie  */
	vector<Spike> rightSpikes;
	/** @brief	Ig�y na g�rnej �cianie  */
	vector<Spike> topSpikes;
	/** @brief	Ig�y na dolnej �cianie  */
	vector<Spike> bottomSpikes;
	/** @brief	Pr�dko�� ptaka */
	Vector2f spikeVelocity;

	/**
	 @fn	int SpikeManager::randomSpikePosition();
	
	 @brief	Losuje pozycje Igiel na scianie lewej i prawej.
	
	 @return	Zwraca pozycje igly na osi Y.
	 */

	int randomSpikePosition();
	/** @brief	Tekstura igly(lewa i prawa sciana)*/
	Texture spikeTexture1;
	/** @brief	Tekstura igly(dolna i gorna)*/
	Texture spikeTexture2;
	/** @brief	Pozycja igly na osi X*/
	int positionX{ 0 };


};

