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
#define POSAWAL_Y  720-127

using namespace sf;
using namespace std;

int main()
{
	cout << "ASISTEN\n=================================" << endl;

	RenderWindow window(VideoMode(PANJANGWINDOW, LEBARWINDOW), "MOVING SPRITE TEST");
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
	float speed = 2, a = 2;
	Vector2f vel(0, 10);
	Vector2f vect;
	bool kunaiState = false;

	Kunai kunai(pos);

	//Loop window
	while (window.isOpen())
	{
		pos = player.getPosisi();
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			move.x = speed;
			player.update(move, a);
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			move.x = - speed;
			player.update(move, -a);
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{

		}
		if (Keyboard::isKeyPressed(Keyboard::Delete))
		{
			player.cekWaktu();
			vect = player.getPosisi();
			cout << "Posisi player ada di: [" << vect.x << ", " << vect.y << "]" << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			player.jumpState = true;
			player.jump(vel, move);
		}

		if (Keyboard::isKeyPressed(Keyboard::F))
		{
			kunaiState = true;
		}

		Event event;
		while (window.pollEvent(event))
		{
			// closing window if close event triggered
			if (event.type == Event::Closed)
				window.close();

		}
		pos = player.getPosisi();

		player.animasi();

		// ngeload background //
		window.clear();
		window.draw(bgPermanen);
		ground.draw(window);
		player.draw(window);
		if (kunaiState == true)
		{
			kunai.draw(window);
			kunai.animasi(pos);
		}
		window.display();
	}


	return 0;
}
