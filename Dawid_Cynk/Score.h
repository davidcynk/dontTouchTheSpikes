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
 @class	Score

 @brief	Klasa obs�ugujaca wynik w grze, w tym liczbe punktow, �yc i dostepnych pauz.

 @author	Dawid Cynk
 @date	15.01.2018
 */

class Score :public ::Drawable
{
public:

	/**
	 @fn	public::Score();
	
	 @brief	Default constructor

	 */

	Score();

	/**
	 @fn	public::~Score();
	
	 @brief	Destructor

	 */

	~Score();

	/**
	 @fn	void public::setPoints(int);
	
	 @brief	Metoda zamieniajaca liczbe punktow.

	 @param	parameter1 liczba punkt�w
	 */

	void setPoints(int);

	/**
	 @fn	int public::getPoints();
	
	 @brief	Metoda zwracajaca liczbe punktow.
	
	 */

	int getPoints();

	/**
	 @fn	void public::setLife(int);
	
	 @brief	Metoda zamieniajaca liczbe �y�.

	 @param	parameter1	liczba �y�.
	 */

	void setLife(int);

	/**
	 @fn	int public::getLife();
	
	 @brief	Metoda zwracaj�ca aktualn� liczb� �y�.
	

	 */

	int getLife();

	/**
	 @fn	void public::countPoints();
	
	 @brief	Metoda licz�ca punkty.

	 */

	void countPoints();

	/**
	 @fn	void public::draw(RenderTarget& target, RenderStates state) const override;
	
	 @brief	Funkcja nadpisana z obiektu Drawable, u�ywana do rysowania obiektu.
	 @author	Dejv
	 @date	15.01.2018
	
	 @param [in,out]	target	Target for the.
	 @param 			state 	The state.
	 */

	void draw(RenderTarget& target, RenderStates state) const override;

	/**
	 @fn	int public::loadFont();
	
	 @brief	Metoda wczytuj�ca czcionk�.
	
	 @author	Dejv
	 @date	15.01.2018
	
	 @return	Zwraca -1 gdy wyst�pi b��d podczas wczytywania czcionki.
	 */

	int loadFont();

	/**
	 @fn	void public::setFont();
	
	 @brief	Metoda ustawiaj�ca paramtery czcionki

	 */

	void setFont();

	/**
	 @fn	void public::countLife();
	
	 @brief	Metoda dodawaj�ca �ycia.

	 */

	void countLife();

	/**
	 @fn	void public::subLife();
	
	 @brief	Metoda odejmuj�ca �ycia.

	 */

	void subLife();

	/**
	 @fn	void public::countPause();
	
	 @brief	Metoda dodawaj�ca pauz�.

	 */

	void countPause();

	/**
	 @fn	void public::subPause();
	
	 @brief	Metoda odejmuj�ca pauz�.

	 */

	void subPause();

	/**
	 @fn	int public::getPause();
	
	 @brief	Metoda zwracaj�ca liczb� pauz.

	 */

	int getPause();

private:
	/** @brief	liczba punkt�w */
	int points{ 0 };
	/** @brief	Liczba �y� */
	int life;
	/** @brief	Liczba �y� */
	int pause;
	/** @brief	Tekst wy�wietlaj�cy liczb� punkt�w */
	Text textPoint;
	/** @brief	Czcionka u�ywana do wy�wietlania punkt�w */
	Font fontPoint;
	/** @brief	tekst wy�wietlaj�cy liczb� �y� */
	Text textLife;
	/** @brief	Czcionka u�ywana do wy�wietlania �y� */
	Font fontLife;
	/** @brief	tekst wy�wietlaj�cy liczb� pauz */
	Text textPause;
	
};

