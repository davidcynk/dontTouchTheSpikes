#include "Spike.h"




Spike::Spike(bool isOnLeft, int Yposition)
{
	loadTexture();
	spike.setOrigin(spike.getGlobalBounds().width / 2, spike.getGlobalBounds().height / 2);
	if (isOnLeft) {
		position.x = 25;
	}
	else {
		position.x = SCREEN_WIDTH - spike.getGlobalBounds().width/2;
	}
	position.y = Yposition;
	spike.setPosition(position);
	
	
}

Spike::~Spike()
{
}

void Spike::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->spike);
}

Sprite *Spike::getSpike()
{
	return &this->spike;

}



int Spike::loadTexture()
{
	if (!spikeTexture.loadFromFile("img/spike2.png"))
		return -1;
	else spike.setTexture(spikeTexture);
	
	
}
