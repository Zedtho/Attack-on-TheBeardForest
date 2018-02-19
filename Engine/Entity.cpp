#include "Entity.h"

void Entity::TakeDamage(int DamageValue)
{
	Health = Health - DamageValue;
};

void Entity::Draw(Graphics& gfx) {
	if (IsAlive)
	{
		for (int TempX = int(entityvec.GetX()); TempX < int(entityvec.GetX()) + Width; TempX++)
		{
			for (int TempY = int(entityvec.GetY()); TempY < int(entityvec.GetY()) + Height; TempY++)
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

