#include "Item.h"



Item::Item()
{
}



Item::~Item()
{
	
}

void Item::setPosition(sf::Vector2i pos)
{
	this->position = pos;
	this->spriteItem.setPosition(position.x,position.y);
	

}

bool Item::checkCollision(Bird * bird, Score * score)
{
	CircleShape circleCandy(25);
	CircleShape circleBird(25);
	circleBird.setPosition(bird->getPosition());
	circleCandy.setPosition(spriteItem.getPosition());
	
	if(circleBird.getGlobalBounds()
		.intersects(circleCandy.getGlobalBounds()))
		{
		collisionReaction(score);
		return true;
		}
}
	  
	

Sprite * Item::getSpriteItem()
{
	return &this->spriteItem;
}

void Item::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->spriteItem);
}

Vector2i Item::randomItemPosition()
{
	int min = 1;
	int maxY = (SCREEN_HEIGHT / 50);
	int maxX = (SCREEN_WIDTH/ 50);

	return Vector2i(((rand() % (maxX - min)) + min) * 45, ((rand() % (maxY - min)) + min) * 45);
}

