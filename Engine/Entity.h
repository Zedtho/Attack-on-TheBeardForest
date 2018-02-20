#pragma once
#include "Graphics.h"
#include "MyVec2.h"
class Entity
{

private:
	MyVec2 Entityvec = MyVec2(100, 200);

	constexpr static float Width = 100;
	constexpr static float Height = 100;

	int DamageValue;
	int Health = 100;
	bool IsAlive = true;

public:
	void CalculateDamageGiven(int DamageValue) {};
	void TakeDamage(int DamageValue);
	void Draw(Graphics& gfx);
	void CheckIfDead();
	Entity(float GivenX, float GivenY, int GivenDamageValue) { Entityvec.x = GivenX; Entityvec.y = GivenY; DamageValue = GivenDamageValue; };
	float GetX() const;
	float GetY() const;
	float GetWidth() const;
	float GetHeight() const;
};