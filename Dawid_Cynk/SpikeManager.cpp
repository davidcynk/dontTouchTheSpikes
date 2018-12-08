#include "SpikeManager.h"



SpikeManager::SpikeManager(Texture *texture)
{
	resetLeftSpikes(0);
	resetRightSpikes(0);
	createBottomTopSpikes();
	
	this->spikeTexture1 = *texture;
}


SpikeManager::~SpikeManager()
{
}

void SpikeManager::resetLeftSpikes(int points)
{
	leftSpikes.clear();
	int amount = 3 + points / 3;
	for (int i = 0; i < amount; i++)
	{
		
		Spike spike(true, randomSpikePosition());
		spike.getSpike()->setTexture(spikeTexture1);
		if (rightSpikes.size()<SCREEN_HEIGHT / 50)
		{ 
		rightSpikes.push_back(spike);
		}
	}

}

void SpikeManager::resetRightSpikes(int points)
{
	
	rightSpikes.clear();
	int amount = 3 + points / 3;
	for (int i = 0; i < amount; i++)
	{
		Spike spike(false, randomSpikePosition());
		spike.getSpike()->setTexture(spikeTexture1);
		spike.getSpike()->setScale(Vector2f{ -1, 1 });
		if (leftSpikes.size()<SCREEN_HEIGHT / 50)
		{
		leftSpikes.push_back(spike);
		}
	}


}
int SpikeManager::createBottomTopSpikes()
{
	Spike spike(false, -300);
	if (!spikeTexture2.loadFromFile("img/spikeTopBottom.png"))
		return -1;
	else spike.getSpike()->setTexture(spikeTexture2);

	for (int i = 0; i < SCREEN_WIDTH/50 + 25; i++)
	{
		spike.getSpike()->setTexture(spikeTexture2);
		spike.getSpike()->setScale(Vector2f{ 1.0f, 1.0f });
		spike.getSpike()->setPosition(this->positionX, 20);
		bottomSpikes.push_back(spike);
		
		spike.getSpike()->setPosition(this->positionX, 750);
		spike.getSpike()->setScale(Vector2f{ 1.0f, -1.0f });
		topSpikes.push_back(spike);
	
		positionX += 50;
	

	}
}
bool SpikeManager::checkCollision(Bird * bird)
{
	CircleShape circleBird(20);
	circleBird.setPosition(bird->getPosition());

	for (int i = 0; i < leftSpikes.size(); i++)
	{
		if (circleBird.getGlobalBounds()
			.intersects(leftSpikes.at(i).getSpike()->getGlobalBounds()))
		{
			leftSpikes.clear();
			
			return true;
			
		}
	}
	for (int i = 0; i < rightSpikes.size(); i++)
	{
		if (circleBird.getGlobalBounds()
			.intersects(rightSpikes.at(i).getSpike()->getGlobalBounds()))
		{
			
			
			rightSpikes.clear();
			
			return true;
			
		}
	}
	
	
	
}

bool SpikeManager::checkCollisionTopBottom(Bird * bird)
{
	CircleShape circleBird(20);
	circleBird.setPosition(bird->getPosition());
	if (circleBird.getPosition().y > SCREEN_HEIGHT - 50 || circleBird.getPosition().y < 50)
	{
		bird->getSprite()->setScale(bird->getSprite()->getScale().x, -1);
		return true;
	}
	
}



void SpikeManager::draw(RenderWindow & window) const
{
	for (int i = 0; i < leftSpikes.size(); i++)
	{
		window.draw(leftSpikes.at(i));
	}
	for (int i = 0; i < rightSpikes.size(); i++)
	{
		window.draw(rightSpikes.at(i));
		
	}
	for (int i = 0; i < topSpikes.size(); i++)
	{
		window.draw(topSpikes.at(i));
	}
	for (int i = 0; i < bottomSpikes.size(); i++)
	{
		window.draw(bottomSpikes.at(i));
	}
}


int SpikeManager::randomSpikePosition()
{
	int min = 1;
	int max = (SCREEN_HEIGHT / 50) + 5;
	return ((rand() % (max - min)) + min)*45;

}


