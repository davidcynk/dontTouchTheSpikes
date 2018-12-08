#include "MenuOptions.h"



MenuOptions::MenuOptions(int textSize)
{
	this->currentPosition = 0;
	this->currentColor = Color::Red;
	font.loadFromFile("font/LIFE.TTF");
	this->textSize = textSize;
}


MenuOptions::~MenuOptions()
{
}

void MenuOptions::addOption(Vector2f position, String name, int val)
{
	item option;
	option.text.setCharacterSize(textSize);
	option.text.setPosition(position);
	option.text.setFillColor(Color::White);
	option.text.setString(name);
	option.text.setOrigin(option.text.getGlobalBounds().width / 2, option.text.getGlobalBounds().height / 2);
	option.text.setFont(font);
	option.returnValue = val;
	options.push_back(option);
}

void MenuOptions::draw(RenderWindow *window)
{
	for (int i = 0; i < options.size(); i++) {
		if (i == currentPosition) {
			options.at(i).setTextColor(currentColor);
		}
		else {
			options.at(i).setTextColor(Color::White);
		}
	}
	for (int i = 0; i < options.size(); i++) {
		window->draw(options.at(i).text);
	}
}


int MenuOptions::getValue()
{
	return options.at(currentPosition).returnValue;
}

void MenuOptions::handleInput(Event * event)
{
	if (event->type == Event::KeyPressed && event->key.code == Keyboard::Down)
	{
		if (currentPosition < options.size() -1) {
			options.at(currentPosition).setTextColor(Color::White);
			currentPosition++;
			options.at(currentPosition).setTextColor(currentColor);
		}
	}
	else if (event->type == Event::KeyPressed && event->key.code == Keyboard::Up)
	{
		if (currentPosition > 0) {
			options.at(currentPosition).setTextColor(Color::White);
			currentPosition--;
			options.at(currentPosition).setTextColor(currentColor);
		}
	}
}
