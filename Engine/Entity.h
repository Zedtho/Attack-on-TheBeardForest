#pragma once
#include "Graphics.h"
#include "MyVec2.h"
#include "RectF.h"
class Entity
{

private:
	

	constexpr static float Width = 100;
	constexpr static float Height = 100;
	RectF EntityRect;

	int DamageValue;
	int Health = 100;
	bool IsAlive = true;

public:
	void CalculateDamageGiven(int DamageValue) {};
	void TakeDamage(int DamageValue);
	void Draw(Graphics& gfx);
	void CheckIfDead();
	Entity(float GivenX, float GivenY, int GivenDamageValue) 
	{ 
	EntityRect.left = GivenX; 
	EntityRect.top = GivenY; 
	EntityRect.right = GivenX + Width; 
	EntityRect.bottom = GivenY + Height;
	DamageValue = GivenDamageValue; 
	};
	float GetX() const;
	float GetY() const;
	float GetWidth() const;
	float GetHeight() const;
	RectF GetRect() const;
};