#include "Entity.h"

void Entity::TakeDamage(float DamageValue)
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

void Entity::Move(float dt, RectF Target)
{
	Vec2f MoveBy;
	if (Target.GetCenter().x > EntityRect.GetCenter().x)
	{
		MoveBy.x + 4 * dt;
	}
	if (Target.GetCenter().x < EntityRect.GetCenter().x)
	{
		MoveBy.x - 4 * dt;
	}
	if (Target.GetCenter.y < EntityRect.GetCenter().y)
	{
		MoveBy.y + 4 * dt;
	}
	if (Target.GetCenter.y > EntityRect.GetCenter().y)
	{
		MoveBy.y - 4 * dt;
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
	return EntityRect.left;
}

float Entity::GetY() const
{
	return EntityRect.top;
}

float Entity::GetWidth() const
{
	return Width;
}

float Entity::GetHeight() const
{
	return Height;
}

RectF Entity::GetRect() const
{
	return EntityRect;
}

