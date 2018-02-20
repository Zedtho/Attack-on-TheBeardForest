#include "Entity.h"

void Entity::TakeDamage(int DamageValue)
{
	Health = Health - DamageValue;
};

void Entity::Draw(Graphics& gfx) {
	if (IsAlive)
	{
		for (int TempX = int(GetX()); TempX < int(GetX()) + Width; TempX++)
		{
			for (int TempY = int(GetY()); TempY < int(GetY()) + Height; TempY++)
			{
				gfx.PutPixel(TempX, TempY, 255, 0, 0);
			}
		}
	}
	else
	{
	  
	}
}

void Entity::CheckIfDead()
{
	if (Health <= 0)
	{
		IsAlive = false;
	}
}

float Entity::GetX() const
{
	return Entityvec.GetX();
}

float Entity::GetY() const
{
	return Entityvec.GetY();
}

float Entity::GetWidth() const
{
	return Width;
}

float Entity::GetHeight() const
{
	return Height;
}

