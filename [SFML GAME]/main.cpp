#include <SFML\Graphics.hpp>
#include <SFML\System\time.hpp>
#include <SFML\System\clock.hpp>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <vector>
#include "Character.h"
#include "Ground.h"
#include "Kunai.h"
#include "Zombie.h"

#define PANJANGWINDOW 1280
#define LEBARWINDOW 720
#define POSAWAL_X 1280/2
#define POSAWAL_Y  720-125

using namespace sf;
using namespace std;

int main()
{
	cout << "ASISTEN\n=================================" << endl;
	srand(time(NULL));
	int f = rand() % 100;
	int b = rand() % 100;
	int c = rand() % 100;
	int d = rand() % 100;
	int e = rand() % 100;
	cout << f << endl << b << endl << c << endl << d << endl << e << endl;

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
	Vector2f move, pos = { POSAWAL_X, POSAWAL_Y - 0.3f * 219.5f }, playerPos;
	Character player(pos, 0.3, 0.3);
	float speed = 4, a = 2;
	Vector2f vel(0, 10);
	Vector2f vect;
	bool kunaiState[100] = { false };
	Vector2i posMouse;
	int mouse_x, mouse_y;
	int i_kunai = 0, kunai_count = 0;
	float posKunai[100];

	bool isFacingRight = true;
	bool isFacingLeft = false;
	bool isMoving = false;
	bool isThrowing = false;
	bool isJumping = false;

	bool kunaiFacingLeft[100] = { false };
	bool kunaiFacingRight[100] = { false };

	Kunai kunai[100];
	Zombie zombie(pos, 0.27, 0.27);

	//Loop window
	while (window.isOpen())
	{
		pos = player.getPosisi();
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			isFacingRight = true;
			isFacingLeft = false;
			if (isThrowing == false)
			{
				if (isMoving = false)
					player.clockRestart();
				isMoving = true;
			}
			move.x = speed;
			player.update(move, a);
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			isFacingRight = false;
			isFacingLeft = true;
			if (isThrowing == false)
			{
				if (isMoving = false)
					player.clockRestart();
				isMoving = true;
			}
			move.x = -speed;
			player.update(move, -a);
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{

		}
		if (Keyboard::isKeyPressed(Keyboard::K))
		{
			if (isThrowing == false)
			{
				cout << "Kunai count is: " << kunai_count << endl;
				isMoving = false;
				player.clockRestart();
				isThrowing = true;
				if (isFacingLeft)
				{
					kunaiFacingLeft[kunai_count] = true;
					kunaiFacingRight[kunai_count] = false;
				}
				else if (isFacingRight)
				{
					kunaiFacingLeft[kunai_count] = false;
					kunaiFacingRight[kunai_count] = true;
				}
				kunai[kunai_count].setPosisi(pos.x, pos.y);
				kunai[kunai_count].setVelocity(isFacingRight, 8, 0);
				kunaiState[kunai_count] = true;
				if (kunai_count < 19)
					kunai_count += 1;
				else
					kunai_count = 0;
			}
		}

		Event event;
		while (window.pollEvent(event))
		{
			// closing window if close event triggered
			if (event.type == Event::Closed)
				window.close();

			if (Mouse::isButtonPressed(Mouse::Right))
			{
				posMouse = Mouse::getPosition(window);
				mouse_x = posMouse.x;
				mouse_y = posMouse.y;
				cout << "Posisi pointer ada di: " << mouse_x << "," << mouse_y << endl;
			}

			if (Keyboard::isKeyPressed(Keyboard::Delete))
			{
				player.cekWaktu();
				pos = player.getPosisi();
				cout << "Posisi player ada di: [" << pos.x << ", " << pos.y << "]" << endl;
			}

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				if (isJumping == false)
				{
					player.clockRestart();
					isJumping = true;
				}
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
		zombie.draw(window);
		for (i_kunai; i_kunai < 20; i_kunai++)
		{
			if (kunaiState[i_kunai] == true)
			{
				if (kunaiFacingLeft[i_kunai])
				{
					posKunai[i_kunai] = kunai[i_kunai].animasi(pos, kunaiFacingRight[i_kunai], kunaiFacingLeft[i_kunai]);
					kunai[i_kunai].draw(window);

					if (posKunai[i_kunai] < 0)
					{
						posKunai[i_kunai] = pos.x;
						kunai[i_kunai].setPosisi(pos.x, pos.y);
						kunaiState[i_kunai] = false;
					}
				}
				else if (kunaiFacingRight[i_kunai])
				{
					posKunai[i_kunai] = kunai[i_kunai].animasi(pos, kunaiFacingRight[i_kunai], kunaiFacingLeft[i_kunai]);
					kunai[i_kunai].draw(window);
					if (posKunai[i_kunai] > 1000)
					{
						posKunai[i_kunai] = pos.x;
						kunai[i_kunai].setPosisi(pos.x, pos.y);
						kunaiState[i_kunai] = false;
					}
				}
			}
		}
		player.draw(window);
		i_kunai = 0;
		window.display();
	}


	return 0;
}
