#include "PlayState.h"



PlayState::PlayState(RenderWindow *window, GameStates * state)
{
 	this->window = window;
	this->state = state;
	this->isGameStarted = false;
	this->isGameOver = false;
	this->isGameFinal = false;
	this->isPaused = false;
}


PlayState::~PlayState()
{
	delete bird;
	delete spikes;
	delete score;
	delete heart;
	delete candy;
	delete pause;
	delete sound;
}

void PlayState::Init()
{
	bird = new Bird(Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	Texture spikeTexture;
	spikeTexture.loadFromFile("img/spike2.png");
	spikes = new SpikeManager(&spikeTexture);
	score = new Score();
	heart = new ItemHeart(score);
	candy = new ItemCandy();
	pause = new ItemPause(score);
	sound = new Sounds(VOLUME_SOUND);
	score->loadFont();
	setBackground();
}

void PlayState::HandleInput()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == Event::Closed)
			window->close();
		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Space && isGameOver == false && isPaused == false)
			{
				isGameStarted = true;
				if (isGameOver == false)
				{
					bird->jump();
				}
				sound->playSoundJump();

			}
			if (event.key.code == Keyboard::P  )
			{	
				if (score->getPause() == 1) {
				score->subPause();
				this->isPaused = true;
				backgroundTexture.loadFromFile("img/tloPause.png");
				backgroundSprite.setTexture(backgroundTexture);
				score->setFont();
				}
				else if (isPaused == true) {
					setBackground();
					isPaused = false;
				}
			}
			if (event.key.code == Keyboard::Escape && isGameStarted==false)
			{
				*this->state = Menu;
			}
		}
	}
}

void PlayState::Update()
{
	if (isGameStarted && isPaused == false) {
		bird->updateMove();
	}

	if (spikes->checkCollision(bird) == true)
	{	
		score->subLife();
	}
	if (spikes->checkCollisionTopBottom(bird) == true || score->getLife() == -1) {
		isGameOver = true;
	}

	
	if (bird->getIsBounced() == true)
	{
		if (bird->getPosition().x < SCREEN_WIDTH / 2)
		{
			spikes->resetRightSpikes(score->getPoints());
			bird->setIsBounced(false);
		}
		else
		{
			spikes->resetLeftSpikes(score->getPoints());
			bird->setIsBounced(false);
		}
		sound->playSoundBounce();
		score->countPoints();
		score->setFont();
		heart->setPosition(heart->randomItemPosition(score));
		pause->setPosition(pause->randomItemPosition(score));
		candy->setPosition(candy->randomItemPosition());
		if (score->getPoints() % 10 == 0)
		{
			setBackground();
		}
	}
	if (bird->getPosition().y > 1068)
	{
		sound->playSoundGameOver();
		this->isGameStarted == false;
		bird->setVelocity(Vector2f{ 0,0 });
		isGameFinal = true;
	}
	if (isGameOver)
	{
		bird->killBird(score);
	}
}

void PlayState::Draw()
{
	window->draw(backgroundSprite);
	if (candy->checkCollision(bird, score) == true)
	{
		score->setFont();
	}
	window->draw(*score);
	if (heart->checkCollision(bird, score) == true)
	{
		score->setFont();
	}
	if (pause->checkCollision(bird, score) == true)
	{
		score->setFont();
	}
	if(isGameStarted==true)
	{ 
	window->draw(*pause);
	window->draw(*heart);
	window->draw(*candy);
	}
	window->draw(*bird);
	spikes->draw(*window);
}

bool PlayState::getGameFinal()
{
	return this->isGameFinal;
}

Score *PlayState::getScore()
{
	return this->score;
}




int PlayState::setBackground()
{
	if (score->getPoints()<10)
	{
		if (!backgroundTexture.loadFromFile("img/tlo11.png"))
			return -1;
		else backgroundSprite.setTexture(backgroundTexture);
	}
	else if (score->getPoints() >= 10 && score->getPoints()<20)
	{
		if (!backgroundTexture.loadFromFile("img/tlo12.jpg"))
			return -1;
		else backgroundSprite.setTexture(backgroundTexture);
	}
	
}
