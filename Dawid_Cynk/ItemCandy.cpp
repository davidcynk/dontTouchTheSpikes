#include "ItemCandy.h"



ItemCandy::ItemCandy()
{
	loadTexture();
	this->position = randomItemPosition();
	spriteItem.setPosition(position.x, position.y);
	spriteItem.setOrigin(25, 25);

}


ItemCandy::~ItemCandy()
{
}

void ItemCandy::collisionReaction(Score *score)
{  
	score->countPoints();
	spriteItem.setPosition(-100, -100);
}

int ItemCandy::loadTexture()
{
	if (!ItemCandyTexture.loadFromFile("img/candy.png"))
		return -1;
	else spriteItem.setTexture(ItemCandyTexture);
}
