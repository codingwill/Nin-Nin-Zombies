#include "Character.h"
#include <iostream>
#define ORIGINSPRITE_X 116
#define ORIGINSPRITE_Y 219.5

Character::Character(const Vector2f& posi, float scale_x, float scale_y)
	:
	pos(posi), scale_x(scale_x), scale_y(scale_y)
{

	pic1.loadFromFile("images/ninja/png/Idle__000.png");
	pic2.loadFromFile("images/ninja/png/Idle__001.png");
	pic3.loadFromFile("images/ninja/png/Idle__002.png");
	pic4.loadFromFile("images/ninja/png/Idle__003.png");
	pic5.loadFromFile("images/ninja/png/Idle__004.png");
	pic6.loadFromFile("images/ninja/png/Idle__005.png");
	pic7.loadFromFile("images/ninja/png/Idle__006.png");
	pic8.loadFromFile("images/ninja/png/Idle__007.png");
	pic9.loadFromFile("images/ninja/png/Idle__008.png");
	pic10.loadFromFile("images/ninja/png/Idle__009.png");

	run1.loadFromFile("images/ninja/png/Run__000.png");
	run2.loadFromFile("images/ninja/png/Run__001.png");
	run3.loadFromFile("images/ninja/png/Run__002.png");
	run4.loadFromFile("images/ninja/png/Run__003.png");
	run5.loadFromFile("images/ninja/png/Run__004.png");
	run6.loadFromFile("images/ninja/png/Run__005.png");
	run7.loadFromFile("images/ninja/png/Run__006.png");
	run8.loadFromFile("images/ninja/png/Run__007.png");
	run9.loadFromFile("images/ninja/png/Run__008.png");
	run10.loadFromFile("images/ninja/png/Run__009.png");

	run1b.loadFromFile("images/ninja/png/Run__000b.png");
	run2b.loadFromFile("images/ninja/png/Run__001b.png");
	run3b.loadFromFile("images/ninja/png/Run__002b.png");
	run4b.loadFromFile("images/ninja/png/Run__003b.png");
	run5b.loadFromFile("images/ninja/png/Run__004b.png");
	run6b.loadFromFile("images/ninja/png/Run__005b.png");
	run7b.loadFromFile("images/ninja/png/Run__006b.png");
	run8b.loadFromFile("images/ninja/png/Run__007b.png");
	run9b.loadFromFile("images/ninja/png/Run__008b.png");
	run10b.loadFromFile("images/ninja/png/Run__009b.png");

	sprite.setOrigin(116, 219.5);
	sprite.setScale(scale_x, scale_y);
	sprite.setTexture(pic1);
	sprite.setPosition(posi);
}



Character::~Character()
{
}

void Character::draw(RenderTarget& rt) const
{
	rt.draw(sprite);
}

void Character::update(Vector2f& velo, float a)
{
	pos = sprite.getPosition();
	pos += velo;
	if (pos.x < ORIGINSPRITE_X * scale_x)
	{
		pos.x = ORIGINSPRITE_X * scale_x;
	}
	else if (pos.y < ORIGINSPRITE_Y * scale_y)
	{
		pos.y = ORIGINSPRITE_Y * scale_y;
	}
	else if (pos.x > 1280-(ORIGINSPRITE_X * scale_x))
		pos.x = 1280-(ORIGINSPRITE_X * scale_x);
	else if (pos.y > 720-(ORIGINSPRITE_Y * scale_y))
		pos.y = 720-(ORIGINSPRITE_Y * scale_y);
	
		sprite.setPosition(pos);
}
const Vector2f& Character::getPosisi()
{
	return sprite.getPosition();
}
void Character::setPosisi(float x, float y)
{
	sprite.setPosition(x, y);
}
void Character::animasi()
{
		time = clock.getElapsedTime();
		currentTime = time.asSeconds();
		if (jumpState)
		{ 
			
		}
		else
		{
			if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::A) == false)
			{
				sprite.setTexture(run1, true);
				if (currentTime >= 10 * runTime / frame)
					clock.restart();
				else if (currentTime >= 9 * runTime / frame)
					sprite.setTexture(run10);
				else if (currentTime >= (8 * runTime / frame))
					sprite.setTexture(run9);
				else if (currentTime >= (7 * runTime / frame))
					sprite.setTexture(run8);
				else if (currentTime >= (6 * runTime / frame))
					sprite.setTexture(run7);
				else if (currentTime >= (5 * runTime / frame))
					sprite.setTexture(run6);
				else if (currentTime >= (4 * runTime / frame))
					sprite.setTexture(run5);
				else if (currentTime >= (3 * runTime / frame))
					sprite.setTexture(run4);
				else if (currentTime >= (2 * runTime / frame))
					sprite.setTexture(run3);
				else if (currentTime >= (1 * runTime / frame))
					sprite.setTexture(run2);
				else if (currentTime >= (0 * runTime / frame))
					sprite.setTexture(run1);
			}
			else if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::D) == false)
			{
				sprite.setTexture(run1b, true);
				if (currentTime >= 10 * runTime / frame)
					clock.restart();
				else if (currentTime >= 9 * runTime / frame)
					sprite.setTexture(run10b);
				else if (currentTime >= (8 * runTime / frame))
					sprite.setTexture(run9b);
				else if (currentTime >= (7 * runTime / frame))
					sprite.setTexture(run8b);
				else if (currentTime >= (6 * runTime / frame))
					sprite.setTexture(run7b);
				else if (currentTime >= (5 * runTime / frame))
					sprite.setTexture(run6b);
				else if (currentTime >= (4 * runTime / frame))
					sprite.setTexture(run5b);
				else if (currentTime >= (3 * runTime / frame))
					sprite.setTexture(run4b);
				else if (currentTime >= (2 * runTime / frame))
					sprite.setTexture(run3b);
				else if (currentTime >= (1 * runTime / frame))
					sprite.setTexture(run2b);
				else if (currentTime >= (0 * runTime / frame))
					sprite.setTexture(run1b);
			}
			else
			{
				sprite.setTexture(pic1, true);
				if (currentTime >= 10 * idleTime / frame)
					clock.restart();
				else if (currentTime >= 9 * idleTime / frame)
					sprite.setTexture(pic10);
				else if (currentTime >= (8 * idleTime / frame))
					sprite.setTexture(pic9);
				else if (currentTime >= (7 * idleTime / frame))
					sprite.setTexture(pic8);
				else if (currentTime >= (6 * idleTime / frame))
					sprite.setTexture(pic7);
				else if (currentTime >= (5 * idleTime / frame))
					sprite.setTexture(pic6);
				else if (currentTime >= (4 * idleTime / frame))
					sprite.setTexture(pic5);
				else if (currentTime >= (3 * idleTime / frame))
					sprite.setTexture(pic4);
				else if (currentTime >= (2 * idleTime / frame))
					sprite.setTexture(pic3);
				else if (currentTime >= (1 * idleTime / frame))
					sprite.setTexture(pic2);
				else if (currentTime >= (0 * idleTime / frame))
					sprite.setTexture(pic1);
			}
		}
		
}

void Character::cekWaktu()
{
	std::cout << "Waktu saat ini: " << currentTime << std::endl;
}

void Character::jump(Vector2f& v, Vector2f& posi)
{
	vel = v - gravity * dt;
	pos += posi + vel * dt;
	sprite.setPosition(pos);
}

