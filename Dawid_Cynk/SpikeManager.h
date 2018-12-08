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

 @brief Menadzer igiel, zawiera metody obs³uguj¹ce zachowanie igiel.

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
	
	 @brief	Resetuje igly znajdujace siê na lewej scianie.
	
	 @param	points - aktualna liczba punktów.
	 */

	void resetLeftSpikes(int points);

	/**
	 @fn	void SpikeManager::resetRightSpikes(int points);
	
	 @brief	Resetuje igly znajdujace siê na prawej scianie.
	
	 
	 @param	points - aktualna liczba punktów.
	 */

	void resetRightSpikes(int points);

	/**
	 @fn	int SpikeManager::createBottomTopSpikes();
	
	 @brief	Tworzy ig³y na dolnej i górnej scianie, wczytuje teksture.
	
	
	
	 @return	Zwraca -1, gdy tekstura nie zostanie wczytana.
	 */

	int createBottomTopSpikes();

	/**
	 @fn	bool SpikeManager::checkCollision(Bird *bird, Score *score);
	
	 @brief	Sprawdza kolizje ptaszka z iglami.
	
	 @param 	bird    wskaznik do obiektyu typu Bird.
	
	 @return	Zwraca prawdê gdy kolizja wystepuje.
	 */

	bool checkCollision(Bird *bird);

	/**
	 @fn	bool SpikeManager::checkCollisionTopBottom(Bird *bird);
	
	 @brief	Sprawdza kolizje z dolna i górna œciana.
	
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
	/** @brief	Ig³y na lewej œcianie */
	vector<Spike> leftSpikes;
	/** @brief	Ig³y na prawej œcianie  */
	vector<Spike> rightSpikes;
	/** @brief	Ig³y na górnej œcianie  */
	vector<Spike> topSpikes;
	/** @brief	Ig³y na dolnej œcianie  */
	vector<Spike> bottomSpikes;
	/** @brief	Prêdkoœæ ptaka */
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

