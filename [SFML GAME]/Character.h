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
	void animasi(bool& isMoving, bool isFacingRight, bool isFacingLeft, bool& isThrowing, bool& isJumping);
	void cekWaktu();
	void jump(Vector2f& v, Vector2f& posi);
	void clockRestart();
	void jumping(Vector2f& posJump, bool& isJumping);


private:
	float accel = 2.0f;
	float currentTime = 0, idleTime = 1.5, runTime = 0.6, throwTime = 0.3, jumpTime = 1;
	float frame = 10, scale_x, scale_y;
	float dt = 0.1f;//THIS IS THE FUCKING CULPRIT! XD

	Vector2f pos, vy, initialPos;
	const Vector2f gravity = { 0, 2 };
	Vector2f velInit = { 0, -7.5 }, vel = velInit;
	Texture pic1, pic2, pic3, pic4, pic5, pic6, pic7, pic8, pic9, pic10;
	Texture run1, run2, run3, run4, run5, run6, run7, run8, run9, run10;
	Texture throw1, throw2, throw3, throw4, throw5, throw6, throw7, throw8, throw9, throw10;
	Texture jump1, jump2, jump3, jump4, jump5, jump6, jump7, jump8, jump9, jump10; 
	Sprite sprite;
	Time time;
	Clock clock;
};


