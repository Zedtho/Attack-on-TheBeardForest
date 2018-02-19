#pragma once
#include "Graphics.h"
#include "MyVec2.h"
class Entity
{
public:
	MyVec2 entityvec = MyVec2(100, 200);

	constexpr static int Width = 100;
	constexpr static int Height = 100;

	int DamageValue;
	int Health = 100;
	bool IsAlive = true;
	
	void CalculateDamageGiven(int DamageValue) {};
	void TakeDamage(int DamageValue);
	void Draw(Graphics& gfx);
	void CheckIfDead();
	Entity(float GivenX, float GivenY, int GivenDamageValue) { entityvec.x = GivenX; entityvec.y = GivenY; DamageValue = GivenDamageValue; };
};