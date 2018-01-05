#pragma once
#include <SFML\Graphics.hpp>

class Kunai
{
public:
	Kunai();
	~Kunai();

private:	
	double dt;
	sf::Vector2f vel;
	sf::Vector2f accel;
	sf::Texture kunPic;
	sf::Sprite kun;
};
