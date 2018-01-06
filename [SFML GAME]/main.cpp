#include <SFML\Graphics.hpp>
#include <SFML\System\time.hpp>
#include <SFML\System\clock.hpp>
#include <cstdio>
#include <iostream>
#include <time.h>
#include <string>
#include "Character.h"
#include "Ground.h"
#include "Kunai.h"

#define PANJANGWINDOW 1280
#define LEBARWINDOW 720
#define POSAWAL_X 1280/2
#define POSAWAL_Y  720-125

using namespace sf;
using namespace std;

int main()
{
	cout << "ASISTEN\n=================================" << endl;

	RenderWindow window(VideoMode(PANJANGWINDOW, LEBARWINDOW), "Nin Nin Zombies");
	window.setVerticalSyncEnabled(true);
	Texture pic_BG;
	pic_BG.loadFromFile("images/graveyard/png/BG.png");
	//Call Sprite object "bgPermanen"
	Sprite bgPermanen;
	bgPermanen.setTexture(pic_BG);
	bgPermanen.setScale(0.645, 0.645);

	//Call Ground object "ground"
	Ground ground;

	Character player({ POSAWAL_X, POSAWAL_Y - 0.3f * 219.5f }, 0.3, 0.3);
	Vector2f move, pos = { POSAWAL_X, POSAWAL_Y - 0.3f * 219.5f }, playerPos;
	float speed = 4, a = 2;
	Vector2f vel(0, 10);
	Vector2f vect;
	bool kunaiState = false;
	float posKunai;

	bool isFacingRight = true;
	bool isFacingLeft = false;
	bool isMoving = false;
	bool isThrowing = false;
	bool isJumping = false;

	bool kunaiFacingLeft = false;
	bool kunaiFacingRight = false;

	Kunai kunai(pos, 0.4, 0.4);

	//Loop window
	while (window.isOpen())
	{
		pos = player.getPosisi();
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			if (isThrowing == false)
			{
				isFacingRight = true;
				isFacingLeft = false;
				if (isMoving = false)
					player.clockRestart();
				isMoving = true;
				move.x = speed;
				player.update(move, a);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			if (isThrowing == false)
			{
				isFacingRight = false;
				isFacingLeft = true;
				if (isMoving = false)
					player.clockRestart();
				isMoving = true;
				move.x = -speed;
				player.update(move, -a);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{

		}

		Event event;
		while (window.pollEvent(event))
		{
			// closing window if close event triggered
			if (event.type == Event::Closed)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Delete))
			{
				player.cekWaktu();
				pos = player.getPosisi();
				cout << "Posisi player ada di: [" << pos.x << ", " << pos.y << "]" << endl;
			}

			if (Keyboard::isKeyPressed(Keyboard::F))
			{
				isMoving = false;
				player.clockRestart();
				isThrowing = true;
				if (isFacingLeft)
				{
					kunaiFacingLeft = true;
					kunaiFacingRight = false;
				}
				else if (isFacingRight)
				{
					kunaiFacingLeft = false;
					kunaiFacingRight = true;
				}
				kunai.setPosisi(pos.x, pos.y);
				kunai.setVelocity(isFacingRight, 8, 0);
				kunaiState = true;
			}

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.clockRestart();
				isJumping = true;

			}


		}
		pos = player.getPosisi();
		if (isJumping)
			player.jumping(pos, isJumping);
		player.animasi(isMoving, isFacingRight, isFacingLeft, isThrowing, isJumping);

		// ngeload background //
		window.clear();
		window.draw(bgPermanen);
		ground.draw(window);
		player.draw(window);
		if (kunaiState == true)
		{
			if (kunaiFacingLeft)
			{
				posKunai = kunai.animasi(pos, kunaiFacingRight, kunaiFacingLeft);
				kunai.draw(window);
				if (posKunai < 0)
				{
					posKunai = pos.x;
					kunai.setPosisi(pos.x, pos.y);
					kunaiState = false;
				}
			}
			else if (kunaiFacingRight)
			{
				posKunai = kunai.animasi(pos, kunaiFacingRight, kunaiFacingLeft);
				kunai.draw(window);
				if (posKunai > 1000)
				{
					posKunai = pos.x;
					kunai.setPosisi(pos.x, pos.y);
					kunaiState = false;
				}
			}

		}
		window.display();
	}


	return 0;
}
