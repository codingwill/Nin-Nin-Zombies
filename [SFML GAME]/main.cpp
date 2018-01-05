#include <SFML\Graphics.hpp>
#include <SFML\System\time.hpp>
#include <SFML\System\clock.hpp>
#include <cstdio>
#include <iostream>
#include <time.h>
#include <string>
#include "Character.h"
#include "Ground.h"

#define PANJANGWINDOW 1280
#define LEBARWINDOW 720
#define POSAWAL_X 1280/2
#define POSAWAL_Y  720-129-130

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

	Character player({ POSAWAL_X, POSAWAL_Y}, 0.3, 0.3);
	Vector2f move = {POSAWAL_X, POSAWAL_Y}, pos;
	float speed = 2;
	Vector2f vel(0, 10);
	Vector2f vect;

	//Loop window
	while (window.isOpen())
	{
		pos = player.getPosisi();
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			move.x += speed;
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			move.x -= speed;
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
		Event event;
		while (window.pollEvent(event))
		{
			// closing window if close event triggered
			if (event.type == Event::Closed)
				window.close();

		}
		pos = player.getPosisi();

		player.update(move);
		player.animasi();

		// ngeload background //
		window.clear();
		window.draw(bgPermanen);
		ground.draw(window);
		player.draw(window);
		window.display();
	}


	return 0;
}
