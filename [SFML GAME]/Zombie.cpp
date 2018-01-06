#include "Zombie.h"
#include <cstdio>

Zombie::Zombie(const Vector2f& posi, float scale_x, float scale_y)
	:
	initPosX(scale_x), initPosY(scale_y)
{
	//430 x 519
	walkPic1.loadFromFile("images/zombie/png/male/Walk (1).png");
	walkPic2.loadFromFile("images/zombie/png/male/Walk (2).png");
	walkPic3.loadFromFile("images/zombie/png/male/Walk (3).png");
	walkPic4.loadFromFile("images/zombie/png/male/Walk (4).png");
	walkPic5.loadFromFile("images/zombie/png/male/Walk (5).png");
	walkPic6.loadFromFile("images/zombie/png/male/Walk (6).png");
	walkPic7.loadFromFile("images/zombie/png/male/Walk (7).png");
	walkPic8.loadFromFile("images/zombie/png/male/Walk (8).png");
	walkPic9.loadFromFile("images/zombie/png/male/Walk (9).png");
	walkPic10.loadFromFile("images/zombie/png/male/Walk (10).png");
	originX = 215.f * initPosX;
	originY = 259.f * initPosY;
	zombie.setOrigin(215, 259);
	zombie.setScale(scale_x, scale_y); 
	zombie.setTexture(walkPic1);
	zombie.setPosition(1000, 720-125);
	printf("[%f, %f]\n", originX, originY);
}


Zombie::~Zombie()
{
}

void Zombie::animasi()
{
	time = clock.getElapsedTime();
	currentTime = time.asSeconds();
}

void Zombie::draw(sf::RenderTarget& rt) const
{
	rt.draw(zombie);
}