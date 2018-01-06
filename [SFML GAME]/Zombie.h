#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Zombie
{
public:
	Zombie(const Vector2f& posi, float scale_x, float scale_y);
	~Zombie();
	void animasi();
	void draw(RenderTarget& rt) const;

private:
	double initPosX, initPosY, originX, originY;
	Texture walkPic1, walkPic2, walkPic3, walkPic4, walkPic5, walkPic6, walkPic7, walkPic8, walkPic9, walkPic10;
	Sprite zombie;
	Time time;
	Clock clock;
	float currentTime;
};

