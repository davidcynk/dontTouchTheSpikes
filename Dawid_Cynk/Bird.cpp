#include "Bird.h"



Bird::Bird(Vector2f position)
{
	this->position = position;
	this->velocity = Vector2f(BIRD_SPEED_X, 0.0f);
	loadTexture();
	birdSprite.setOrigin(25, 25);
	birdSprite.setPosition(position);
	this->isBounced = false;
}


Bird::~Bird()
{
}




int Bird::loadTexture()
{

	if (!BirdTexture.loadFromFile("img/flappy2.png"))
		return -1;
	else birdSprite.setTexture(BirdTexture);
}





void Bird::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->birdSprite);
}

void Bird::updateMove()
{
	velocity.y += GRAVITY;
	if (velocity.y < -12) velocity.y = -12;
	position.y += velocity.y;
	position.x += velocity.x;
	birdSprite.setPosition(position);

	if (position.x >= SCREEN_WIDTH - birdSprite.getGlobalBounds().width/2) 
	{
		velocity.x = -velocity.x;
		birdSprite.setScale(Vector2f{ -1, birdSprite.getScale().y });
		this->isBounced = true;
	}
	if (position.x <= 0 + birdSprite.getGlobalBounds().width / 2) 
	{
		velocity.x = -velocity.x;
		birdSprite.setScale(Vector2f{ 1,birdSprite.getScale().y });
		this->isBounced = true;
	}
	
}

bool Bird::getIsBounced()
{
	return this->isBounced;
}

void Bird::setIsBounced(bool bounced)
{
	this->isBounced = bounced;
}

void Bird::jump()
{
	if (velocity.y > 0) velocity.y /= 2;
	velocity.y -= 10;
}

Sprite * Bird::getSprite()
{
	return &this->birdSprite;
}

Vector2f Bird::getPosition()
{
	return this->position;
}

void Bird::killBird(Score *score)
{
		birdSprite.setScale(birdSprite.getScale().x, -1);

		if (position.x >= SCREEN_WIDTH - birdSprite.getGlobalBounds().width / 2)
		{
			velocity.x = -(BIRD_SPEED_X / 2);


		}
		if (position.x <= 0 + birdSprite.getGlobalBounds().width / 2)
		{
			velocity.x = BIRD_SPEED_X / 2;


		}	
}

void Bird::setVelocity(Vector2f velocity)
{
	this->velocity = velocity;
}





