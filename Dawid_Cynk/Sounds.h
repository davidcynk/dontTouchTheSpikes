#pragma once
#include <SFML\Audio.hpp>

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
 @class	Sounds

 @brief	Klasa obs³ugujaca dzwiek w grze.

 @author	Dawid Cynk
 @date	15.01.2018
 */

class Sounds
{
public:

	/**
	 @fn	Sounds::Sounds(int volume);
	
	 @brief	Constructor

	
	 @param	volume g³osnosc dzwieku.
	 */

	Sounds(int volume);

	/**
	 @fn	Sounds::~Sounds();
	
	 @brief	Destructor

	 */

	~Sounds();

	/**
	 @fn	int Sounds::loadBuffer();
	
	 @brief	Metoda wczytujaca dzwiek.

	
	 @return	zwraca -1 gdy b³ad podczas wczytywania.
	 */

	int loadBuffer();

	/**
	 @fn	void Sounds::playSoundBounce();
	
	 @brief	Metoda odtwarzajaca dzwiek odbicia.

	 */

	void playSoundBounce();

	/**
	 @fn	void Sounds::playSoundGameOver();
	
	 @brief	Metoda odtwarzajaca dzwiek skucia sie.

	 */

	void playSoundGameOver();

	/**
	 @fn	void Sounds::playSoundJump();
	
	 @brief Metoda odtwarzajaca dzwiek skakania.

	 */

	void playSoundJump();
	

private:
	/** @brief	Buffer do wczytania dzwieku odbicia */
	SoundBuffer bounceBuffer;
	/** @brief	Buffer do wczytania dzwieku skucia sie */
	SoundBuffer gameOverBuffer;
	/** @brief	Buffer do wczytania dzwieku skakania*/
	SoundBuffer jumpBuffer;
	/** @brief	Dzwiek odbicia */
	Sound soundBounce;
	/** @brief	Dzwiek skucia sie */
	Sound soundGameOver;
	/** @brief	Dzwiek skoku */
	Sound soundJump;
	
	/** @brief	Glosnosc dzwieku */
	int soundVolume;


};

