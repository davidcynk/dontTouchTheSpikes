#include "Sounds.h"



Sounds::Sounds(int volume)
{
	this->soundVolume = volume;
	soundBounce.setVolume(soundVolume);
	soundGameOver.setVolume(soundVolume);
	soundJump.setVolume(soundVolume);
	loadBuffer();
}


Sounds::~Sounds()
{
}

int Sounds::loadBuffer()
{

	if (!bounceBuffer.loadFromFile("sounds/ODBICIE.ogg"))
		return -1;
	else	soundBounce.setBuffer(bounceBuffer);	
	
	if (!gameOverBuffer.loadFromFile("sounds/PRZEGRANA.ogg"))
		return -1;
	else	soundGameOver.setBuffer(gameOverBuffer);

	if (!jumpBuffer.loadFromFile("sounds/SKOK.ogg"))
		return -1;
	else	soundJump.setBuffer(jumpBuffer);
}

void Sounds::playSoundBounce()
{
	this->soundBounce.play();
}

void Sounds::playSoundGameOver()
{
	this->soundGameOver.play();
}

void Sounds::playSoundJump()
{
	this->soundJump.play();
}

