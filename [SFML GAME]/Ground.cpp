#include "Ground.h"



Ground::Ground()
{
	pGround1.loadFromFile("images/graveyard/png/Tiles/Tile (1).png");
	pGround2.loadFromFile("images/graveyard/png/Tiles/Tile (2).png");
	pGround3.loadFromFile("images/graveyard/png/Tiles/Tile (3).png");
	pGroundFull.loadFromFile("images/GroundFull.png");
	ground1.setTexture(pGround1);
	ground2.setTexture(pGround2);
	ground3.setTexture(pGround3);
	groundFull.setTexture(pGroundFull);
	ground1.setPosition({0, 720-128});
	groundFull.setPosition({ 128, 720 - 128 });
	ground3.setPosition({ 1280 - 128, 720 - 128 });
}

void Ground::draw(sf::RenderTarget& rt) const
{
	rt.draw(ground1);
	rt.draw(groundFull);
	rt.draw(ground3);

}

Ground::~Ground()
{
}
