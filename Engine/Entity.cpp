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
	MoveBy.x = 0;
	MoveBy.y = 0;
	if (Target.GetCenter().x > EntityRect.GetCenter().x)
	{
		MoveBy.x += 120 * dt;
	}
	else if (Target.GetCenter().x < EntityRect.GetCenter().x)
	{
		MoveBy.x -= 120 * dt;
	}
	if (Target.GetCenter().y < EntityRect.GetCenter().y)
	{
		MoveBy.y -= 120 * dt;
	}
	else if (Target.GetCenter().y > EntityRect.GetCenter().y)
	{
		MoveBy.y += 120 * dt;
	}
	EntityRect.top += MoveBy.y;
	EntityRect.bottom += MoveBy.y;
	EntityRect.left += MoveBy.x;
	EntityRect.right += MoveBy.x;
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

