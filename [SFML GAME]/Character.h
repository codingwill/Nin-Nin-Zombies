#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace sf;

class Character
{
public:
	Vector2f posnow;
	bool jumpState = false;
public:
	Character::Character(const Vector2f& posi, float scale_x, float scale_y);
	~Character();
	void draw(RenderTarget& rt) const;
	void update(Vector2f& posi, float a);
	const Vector2f& getPosisi();
	void setPosisi(float x, float y);
	void animasi();
	void cekWaktu();
	void jump(Vector2f& v, Vector2f& posi);


private:
	float accel = 2.0f;
	float currentTime = 0, idleTime = 1.5, runTime = 0.6;
	float frame = 10, scale_x, scale_y;
	float dt = 0.00000000000001f;

	Vector2f pos, vy = { 0, 6 }, initialPos, gravity = { 0, -2 };
	Vector2f vel;
	Texture pic1, pic2, pic3, pic4, pic5, pic6, pic7, pic8, pic9, pic10;
	Texture run1, run2, run3, run4, run5, run6, run7, run8, run9, run10;
	Texture run1b, run2b, run3b, run4b, run5b, run6b, run7b, run8b, run9b, run10b;
	Sprite sprite;
	Time time;
	Clock clock;
};


