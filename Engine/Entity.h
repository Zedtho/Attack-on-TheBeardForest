#pragma once
#include "Graphics.h"
#include "Rect.h"

class Entity
{

private:
	

	constexpr static float Width = 100;
	constexpr static float Height = 100;
	RectF EntityRect;

	float DamageValue;
	float Health = 100;
	bool IsAlive = true;

public:
	void CalculateDamageGiven(int DamageValue) {};
	void TakeDamage(float DamageValue);
	void Draw(Graphics& gfx);
	void Move(float dt, RectF Target);
	void CheckIfDead();
	Entity(float GivenX, float GivenY, float GivenDamageValue)
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