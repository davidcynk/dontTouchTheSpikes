#pragma once

/**
 @class	State

 @brief	Klasa obslugujaca interfejs wirtualnego stanu Gry.

 @author	Dawid Cynk
 @date	11.01.2018
 */

class State
{
public:

	/**
	 @fn	virtual void State::Init() = 0;
	
	 @brief	Inicjalizuje stan.

	 */

	virtual void Init() = 0;

	/**
	 @fn	virtual void State::HandleInput() = 0;
	
	 @brief	Obs³uguje wejscie stanu, w zale¿noœci od naszego wyboru.

	 */

	virtual void HandleInput() = 0;

	/**
	 @fn	virtual void State::Update() = 0;
	
	 @brief	Aktualizuje stan gry.
	 */

	virtual void Update() = 0;

	/**
	 @fn	virtual void State::Draw() = 0;
	
	 @brief	Rysuje konkretny stan w oknie.
	
	 */

	virtual void Draw() = 0;
protected:

	/**
	 @enum	GameStates
	
	 @brief	Typ wyliczeniowy zawieraj¹cy wszystkie stany uzywany do przechodzenia miedzy stanami gry.
	 */

	enum GameStates { Splash, Menu, Play};
	
};

