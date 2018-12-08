#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <vector>

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
 @class	MenuOptions

 @brief	Klasa obslugujaca opcje menu.

 @author	Dawid Cynk
 @date	15.01.2018
 */

class MenuOptions
{
public:

	/**
	 @fn	MenuOptions::MenuOptions(int textSize);
	
	 @brief	Constructor

	
	 @param	textSize	rozmiar tekstu.
	 */

	MenuOptions(int textSize);

	/**
	 @fn	MenuOptions::~MenuOptions();
	
	 @brief	Destructor
	
	 */

	~MenuOptions();

	/**
	 @class	item
	
	 @brief	Klasa uzywana tylko w klasie MenuOptions, 
			sluzy do przechowywania tekstu i zwracania wartosci.
	

	 */

	class item {
	public:
		/** @brief	Obiekt typu Text */
		Text text;
		/** @brief Przechowuje zwaracan� warto�� */
		int returnValue;

		/**
		 @fn	void item::setTextColor(Color color)
		
		 @brief	Metoda zamieniaj�ca kolor tekstu.

		 @param	color	The color.
		 */

		void setTextColor(Color color) {
			this->text.setFillColor(color);
		}
	};

	/**
	 @fn	void MenuOptions::addOption(Vector2f position, String name, int val);
	
	 @brief Dodaje kolejn� opcj� wyboru.

	 @param	position	pozycja kolejnej opcji wyboru
	 @param	name		nazwa kolejnej opcji wyboru
	 @param	val			zwracana warto�� kolejnej opcji wyboru
	 */

	void addOption(Vector2f position, String name, int val);

	/**
	 @fn	void MenuOptions::draw(RenderWindow *window);
	
	 @brief	Metoda s�u�y do wy�wietlania wszystkich opcji.

	
	 @param	window	wskaznik do aktualnego okna.
	 */

	void draw(RenderWindow *window);

	/**
	 @fn	int MenuOptions::getValue();
	
	 @brief	Metoda zwracaj�ca warto�� aktualnie zaznaczonej opcji.
	
	 */

	int getValue();

	/**
	 @fn	void MenuOptions::handleInput(Event *event);
	
	 @brief	Metoda umo�liwiaj�ca wyb�r opcji.

	 @param event	wskaznik do obiektu typu Event.
	 */

	void handleInput(Event *event);
private:
	/** @brief	Obecnie zaznaczona opcja */
	int currentPosition;
	/** @brief	wektor przechowuj�cy opcje wyboru */
	vector<item> options;
	/** @brief	Kolor obecnie zaznaczonej opcji */
	Color currentColor;
	/** @brief	Czcionka opcji */
	Font font;
	/** @brief	Rozmiar tekstu */
	int textSize;
};

