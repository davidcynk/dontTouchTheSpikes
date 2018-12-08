#include "ItemPause.h"



ItemPause::ItemPause(Score *score)
{
	loadTexture();
	this->position = randomItemPosition(score);
	spriteItem.setPosition(position.x, position.y);
	spriteItem.setOrigin(25, 25);
}


ItemPause::~ItemPause()
{
}

Vector2i ItemPause::randomItemPosition(Score * score)
{
	if (score->getPoints() % 4 == 0)
	{
		int min = 1;
		int maxY = (SCREEN_HEIGHT / 50);
		int maxX = (SCREEN_WIDTH / 50);

		return Vector2i(((rand() % (maxX - min)) + min) * 45, ((rand() % (maxY - min)) + min) * 45);
	}
	else return Vector2i{ -100,-100 };
}


void ItemPause::collisionReaction(Score * score)
{
	score->countPause();
	spriteItem.setPosition(-200, -100);
}

int ItemPause::loadTexture()
{
	if (!ItemPauseTexture.loadFromFile("img/pause.png"))
		return -1;
	else spriteItem.setTexture(ItemPauseTexture);
}
