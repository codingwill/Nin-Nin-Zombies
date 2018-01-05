#pragma once
#include <SFML\Graphics.hpp>

class Kunai
{
public:
	Kunai(const sf::Vector2f& playerPos);
	~Kunai();
	void draw(sf::RenderTarget& rt) const;
	void animasi(sf::Vector2f& posi);

private:	
	double dt = 0.1f;
	sf::Vector2f vel = { 0, 0 }, pos;
	sf::Vector2f accel = { 2, 0 };
	sf::Texture kunPic;
	sf::Sprite kun;
};
