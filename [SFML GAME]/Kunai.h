#pragma once
#include <SFML\Graphics.hpp>

class Kunai
{
public:
	Kunai(const sf::Vector2f& playerPos, float scale_x, float scale_y);
	~Kunai();
	void draw(sf::RenderTarget& rt) const;
	float animasi(sf::Vector2f& posi, bool isFacingRight, bool isFacingLeft);
	void setPosisi(float x, float y);
	void setVelocity(bool isFacingRight, float x, float y);

private:	
	float scale_x, scale_y;
	sf::Texture kunPic; //32x160 px
	sf::Sprite kun;
	double dt = 0.1f;
	sf::Vector2f vel = { 0, 0 }, pos;
	sf::Vector2f accel = { 5, 0 };
};
