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

 @brief	Klasa obs³ugujaca wynik w grze, w tym liczbe punktow, ¿yc i dostepnych pauz.

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

	 @param	parameter1 liczba punktów
	 */

	void setPoints(int);

	/**
	 @fn	int public::getPoints();
	
	 @brief	Metoda zwracajaca liczbe punktow.
	
	 */

	int getPoints();

	/**
	 @fn	void public::setLife(int);
	
	 @brief	Metoda zamieniajaca liczbe ¿yæ.

	 @param	parameter1	liczba ¿yæ.
	 */

	void setLife(int);

	/**
	 @fn	int public::getLife();
	
	 @brief	Metoda zwracaj¹ca aktualn¹ liczbê ¿yæ.
	

	 */

	int getLife();

	/**
	 @fn	void public::countPoints();
	
	 @brief	Metoda licz¹ca punkty.

	 */

	void countPoints();

	/**
	 @fn	void public::draw(RenderTarget& target, RenderStates state) const override;
	
	 @brief	Funkcja nadpisana z obiektu Drawable, u¿ywana do rysowania obiektu.
	 @author	Dejv
	 @date	15.01.2018
	
	 @param [in,out]	target	Target for the.
	 @param 			state 	The state.
	 */

	void draw(RenderTarget& target, RenderStates state) const override;

	/**
	 @fn	int public::loadFont();
	
	 @brief	Metoda wczytuj¹ca czcionkê.
	
	 @author	Dejv
	 @date	15.01.2018
	
	 @return	Zwraca -1 gdy wyst¹pi b³¹d podczas wczytywania czcionki.
	 */

	int loadFont();

	/**
	 @fn	void public::setFont();
	
	 @brief	Metoda ustawiaj¹ca paramtery czcionki

	 */

	void setFont();

	/**
	 @fn	void public::countLife();
	
	 @brief	Metoda dodawaj¹ca ¿ycia.

	 */

	void countLife();

	/**
	 @fn	void public::subLife();
	
	 @brief	Metoda odejmuj¹ca ¿ycia.

	 */

	void subLife();

	/**
	 @fn	void public::countPause();
	
	 @brief	Metoda dodawaj¹ca pauzê.

	 */

	void countPause();

	/**
	 @fn	void public::subPause();
	
	 @brief	Metoda odejmuj¹ca pauzê.

	 */

	void subPause();

	/**
	 @fn	int public::getPause();
	
	 @brief	Metoda zwracaj¹ca liczbê pauz.

	 */

	int getPause();

private:
	/** @brief	liczba punktów */
	int points{ 0 };
	/** @brief	Liczba ¿yæ */
	int life;
	/** @brief	Liczba ¿yæ */
	int pause;
	/** @brief	Tekst wyœwietlaj¹cy liczbê punktów */
	Text textPoint;
	/** @brief	Czcionka u¿ywana do wyœwietlania punktów */
	Font fontPoint;
	/** @brief	tekst wyœwietlaj¹cy liczbê ¿yæ */
	Text textLife;
	/** @brief	Czcionka u¿ywana do wyœwietlania ¿yæ */
	Font fontLife;
	/** @brief	tekst wyœwietlaj¹cy liczbê pauz */
	Text textPause;
	
};

