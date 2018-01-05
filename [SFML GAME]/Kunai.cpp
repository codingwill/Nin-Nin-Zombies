#include "Kunai.h"



Kunai::Kunai(const sf::Vector2f& playerPos)
{
	kunPic.loadFromFile("images/ninja/png/Kunai.png");
	kun.setTexture(kunPic);
	kun.setScale(0.5, 0.5);
	kun.setRotation(90);
	kun.setPosition(playerPos);
}


Kunai::~Kunai()
{
}

void Kunai::draw(sf::RenderTarget& rt) const
{
	rt.draw(kun);
}


void Kunai::animasi(sf::Vector2f& posi)
{
	posi = kun.getPosition();
	if (posi.x < 1350)
	{
		vel.x += accel.x * dt;
		posi.x += vel.x;
		kun.setPosition(posi);
	}
}
