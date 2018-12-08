#include "Score.h"



Score::Score()
{
	this->life = 0;
	this->pause = 0;
}


Score::~Score()
{
}


void Score::setPoints(int p1)
{
	this->points = p1;
}

int Score::getPoints()
{
	return this->points;
}

void Score::setLife(int life)
{
	this->life = life;
}

int Score::getLife()
{
	return this->life;
}

void Score::countPoints()
{
	points++;


}

void Score::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->textPoint);
	target.draw(this->textLife);
	target.draw(this->textPause);
}

int Score::loadFont()
{
	if (!fontPoint.loadFromFile("font/fonts2.ttf"))
	{
		return -1;
	}
	else {
		textPoint.setFont(fontPoint);
		textLife.setFont(fontPoint);
		textPause.setFont(fontPoint);
	}
	
}

void Score::setFont()
{
	textPoint.setCharacterSize(200);
	textPoint.setPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - 50);
	textPoint.setFillColor(Color::Red);
	textPoint.setString(to_string(getPoints()));
	textPoint.setOrigin(textPoint.getGlobalBounds().width / 2, textPoint.getGlobalBounds().height / 2);

	textPause.setCharacterSize(75);
	textPause.setPosition(100, SCREEN_HEIGHT - 100);
	textPause.setFillColor(Color::Green);
	textPause.setString(to_string(getPause()));
	textPause.setOrigin(textPause.getGlobalBounds().width / 2, textPause.getGlobalBounds().height / 2);

	textLife.setCharacterSize(75);
	textLife.setPosition(SCREEN_WIDTH - 100, SCREEN_HEIGHT - 100);
	textLife.setFillColor(Color::Yellow);

	if (getLife() >= 0) {
	textLife.setString(to_string(getLife()));
	}
	else {
		textLife.setString("Game Over");
		textLife.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT - 100);
	}
	textLife.setOrigin(textLife.getGlobalBounds().width / 2, textLife.getGlobalBounds().height / 2);

}

void Score::countLife()
{
	this->life++;
}

void Score::subLife()
{ 
	this->life--;

}

void Score::countPause()
{
	if (pause == 1)
	{
		this->pause;
	}
	else
	{
	this->pause++;
	}
}

void Score::subPause()
{
	this->pause--;
}

int Score::getPause()
{
	return this->pause;
}


