#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Ground
{
public:
	Ground();
	~Ground();
	void draw(sf::RenderTarget& rt) const;
public:
	sf::Texture pGround1, pGround2, pGround3, pGroundFull; //picture/texture of Ground
	sf::Sprite ground1, ground2, ground3, groundFull; // Sprite of Ground
private:

};

