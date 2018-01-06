#include "Kunai.h"



Kunai::Kunai()
{
	scale_x = 0.4;
	scale_y = 0.4;
	kunPic.loadFromFile("images/ninja/png/Kunai.png");
	kun.setTexture(kunPic);
	kun.setScale(scale_x, scale_y);
	kun.setRotation(90);
	kun.setOrigin(16, 80);
}


Kunai::~Kunai()
{
}

void Kunai::draw(sf::RenderTarget& rt) const
{
	rt.draw(kun);
}


float Kunai::animasi(sf::Vector2f& posi, bool isFacingRight, bool isFacingLeft)
{
	posi = kun.getPosition();
	if (isFacingRight)
	{
		kun.setScale(scale_x, scale_y);
		if (posi.x < 1200)
		{
			vel.x += accel.x * dt;
			posi.x += vel.x;
			kun.setPosition(posi);
		}
		else
			return posi.x;
	}
	else
	{
		kun.setScale(scale_x, -scale_y);

		if (posi.x > 0.0f)
		{
			vel.x += -accel.x * dt;
			posi.x += vel.x;
			kun.setPosition(posi);
		}
		else
			return posi.x;
	}


}

void Kunai::setVelocity(bool isFacingRight, float x, float y)
{
	if (isFacingRight)
		vel.x = x;
	else
		vel.x = -x;
	vel.y = y;
}

void Kunai::setPosisi(float x, float y)
{
	kun.setPosition(x, y);
}
