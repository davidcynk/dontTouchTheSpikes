#include "ItemHeart.h"



ItemHeart::ItemHeart(Score *score)
{
	loadTexture();
	this->position = randomItemPosition(score);
	spriteItem.setPosition(position.x,position.y);
	spriteItem.setOrigin(25, 25);

	

}



ItemHeart::~ItemHeart()
{
}

Vector2i ItemHeart::randomItemPosition(Score *score)
{
if(score->getPoints() %3 == 0)
{ 
	int min = 1;
	int maxY = (SCREEN_HEIGHT / 50);
	int maxX = (SCREEN_WIDTH / 50);

	return Vector2i(((rand() % (maxX - min)) + min) * 45, ((rand() % (maxY - min)) + min) * 45);
}
else return Vector2i{-100,-100};
}


void ItemHeart::collisionReaction(Score *score)
{
	score->countLife();
	spriteItem.setPosition(-200, -100);
}

int ItemHeart::loadTexture()
{
	if (!ItemHeartTexture.loadFromFile("img/heart.png"))
		return -1;
	else spriteItem.setTexture(ItemHeartTexture);
}


