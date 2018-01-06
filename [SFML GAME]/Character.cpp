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

	throw1.loadFromFile("images/ninja/png/Throw__000.png");
	throw2.loadFromFile("images/ninja/png/Throw__001.png");
	throw3.loadFromFile("images/ninja/png/Throw__002.png");
	throw4.loadFromFile("images/ninja/png/Throw__003.png");
	throw5.loadFromFile("images/ninja/png/Throw__004.png");
	throw6.loadFromFile("images/ninja/png/Throw__005.png");
	throw7.loadFromFile("images/ninja/png/Throw__006.png");
	throw8.loadFromFile("images/ninja/png/Throw__007.png");
	throw9.loadFromFile("images/ninja/png/Throw__008.png");
	throw10.loadFromFile("images/ninja/png/Throw__009.png");

	//362x483
	jump1.loadFromFile("images/ninja/png/Jump__000.png");
	jump2.loadFromFile("images/ninja/png/Jump__001.png");
	jump3.loadFromFile("images/ninja/png/Jump__002.png");
	jump4.loadFromFile("images/ninja/png/Jump__003.png");
	jump5.loadFromFile("images/ninja/png/Jump__004.png");
	jump6.loadFromFile("images/ninja/png/Jump__005.png");
	jump7.loadFromFile("images/ninja/png/Jump__006.png");
	jump8.loadFromFile("images/ninja/png/Jump__007.png");
	jump9.loadFromFile("images/ninja/png/Jump__008.png");
	jump10.loadFromFile("images/ninja/png/Jump__009.png");

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
void Character::animasi(bool& isMoving, bool isFacingRight, bool isFacingLeft, bool& isThrowing, bool& isJumping)
{
	time = clock.getElapsedTime();
	currentTime = time.asSeconds();
	if (isFacingRight && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && isMoving && isJumping == false)
		{
			sprite.setOrigin(181.5, 229);
			sprite.setTexture(run1, true);
			sprite.setScale(scale_x, scale_y);
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
	else if (isFacingLeft && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && isMoving && isJumping == false)
		{
			sprite.setOrigin(181.5, 229);
			sprite.setTexture(run1, true);
			sprite.setScale(-scale_x, scale_y);
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
	else if (isFacingLeft && isThrowing)
		{
			isMoving = false;
			sprite.setOrigin(188.5, 225.5);
			sprite.setTexture(throw1, true);
			sprite.setScale(-scale_x, scale_y);
			if (currentTime >= 10 * throwTime / frame)
			{
				isThrowing = false;
				clock.restart();
			}
			else if (currentTime >= 9 * throwTime / frame)
				sprite.setTexture(throw10);
			else if (currentTime >= (8 * throwTime / frame))
				sprite.setTexture(throw9);
			else if (currentTime >= (7 * throwTime / frame))
				sprite.setTexture(throw8);
			else if (currentTime >= (6 * throwTime / frame))
				sprite.setTexture(throw7);
			else if (currentTime >= (5 * throwTime / frame))
				sprite.setTexture(throw6);
			else if (currentTime >= (4 * throwTime / frame))
				sprite.setTexture(throw5);
			else if (currentTime >= (3 * throwTime / frame))
				sprite.setTexture(throw4);
			else if (currentTime >= (2 * throwTime / frame))
				sprite.setTexture(throw3);
			else if (currentTime >= (1 * throwTime / frame))
				sprite.setTexture(throw2);
			else if (currentTime >= (0 * throwTime / frame))
				sprite.setTexture(throw1);
		}
	else if (isFacingRight && isThrowing)
		{
			sprite.setOrigin(188.5, 225.5);
			isMoving = false;
			sprite.setTexture(throw1, true);
			sprite.setScale(scale_x, scale_y);
			if (currentTime >= 10 * throwTime / frame)
			{
				isThrowing = false;
				clock.restart();
			}
			else if (currentTime >= 9 * throwTime / frame)
				sprite.setTexture(throw10);
			else if (currentTime >= (8 * throwTime / frame))
				sprite.setTexture(throw9);
			else if (currentTime >= (7 * throwTime / frame))
				sprite.setTexture(throw8);
			else if (currentTime >= (6 * throwTime / frame))
				sprite.setTexture(throw7);
			else if (currentTime >= (5 * throwTime / frame))
				sprite.setTexture(throw6);
			else if (currentTime >= (4 * throwTime / frame))
				sprite.setTexture(throw5);
			else if (currentTime >= (3 * throwTime / frame))
				sprite.setTexture(throw4);
			else if (currentTime >= (2 * throwTime / frame))
				sprite.setTexture(throw3);
			else if (currentTime >= (1 * throwTime / frame))
				sprite.setTexture(throw2);
			else if (currentTime >= (0 * throwTime / frame))
				sprite.setTexture(throw1);
		}
	else if (isFacingRight && isJumping == false)
		{
			isMoving = false;
			sprite.setOrigin(116, 219.5);
			sprite.setTexture(pic1, true);
			sprite.setScale(scale_x, scale_y);
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
	else if (isFacingLeft && isJumping == false)
		{
			isMoving = false;
			sprite.setOrigin(116, 219.5);
			sprite.setTexture(pic1, true);
			sprite.setScale(-scale_x, scale_y);
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
	else if (isFacingRight && isJumping)
		{
			isMoving = false; 
			sprite.setOrigin(181, 241.5);
			sprite.setTexture(jump1, true);
			sprite.setScale(scale_x, scale_y);
			if (currentTime >= 10 * idleTime / frame)
				clock.restart();
			else if (currentTime >= 9 * idleTime / frame)
				sprite.setTexture(jump10);
			else if (currentTime >= (8 * idleTime / frame))
				sprite.setTexture(jump9);
			else if (currentTime >= (7 * idleTime / frame))
				sprite.setTexture(jump8);
			else if (currentTime >= (6 * idleTime / frame))
				sprite.setTexture(jump7);
			else if (currentTime >= (5 * idleTime / frame))
				sprite.setTexture(jump6);
			else if (currentTime >= (4 * idleTime / frame))
				sprite.setTexture(jump5);
			else if (currentTime >= (3 * idleTime / frame))
				sprite.setTexture(jump4);
			else if (currentTime >= (2 * idleTime / frame))
				sprite.setTexture(jump3);
			else if (currentTime >= (1 * idleTime / frame))
				sprite.setTexture(jump2);
			else if (currentTime >= (0 * idleTime / frame))
				sprite.setTexture(jump1);
		}
	else if (isFacingLeft && isJumping)
		{
			isMoving = false;
			sprite.setOrigin(181, 241.5);
			sprite.setTexture(jump1, true);
			sprite.setScale(-scale_x, scale_y);
			if (currentTime >= 10 * idleTime / frame)
				clock.restart();
			else if (currentTime >= 9 * idleTime / frame)
				sprite.setTexture(jump10);
			else if (currentTime >= (8 * idleTime / frame))
				sprite.setTexture(jump9);
			else if (currentTime >= (7 * idleTime / frame))
				sprite.setTexture(jump8);
			else if (currentTime >= (6 * idleTime / frame))
				sprite.setTexture(jump7);
			else if (currentTime >= (5 * idleTime / frame))
				sprite.setTexture(jump6);
			else if (currentTime >= (4 * idleTime / frame))
				sprite.setTexture(jump5);
			else if (currentTime >= (3 * idleTime / frame))
				sprite.setTexture(jump4);
			else if (currentTime >= (2 * idleTime / frame))
				sprite.setTexture(jump3);
			else if (currentTime >= (1 * idleTime / frame))
				sprite.setTexture(jump2);
			else if (currentTime >= (0 * idleTime / frame))
				sprite.setTexture(jump1);
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

void Character::clockRestart()
{
	clock.restart();
}

void Character::jumping(sf::Vector2f& posJump, bool& isJumping)
{
	vel.y += gravity.y * dt;
	posJump.y += vel.y;
	sprite.setPosition(posJump);
	posJump = sprite.getPosition();
	if (posJump.y > 529.15)
	{
		isJumping = false;
		sprite.setPosition(posJump.x, posJump.y);
		vel.y = velInit.y;//YASSSSSS AKHIRNYA!!!
	}
}