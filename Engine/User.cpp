#pragma once
#include "User.h"


void User::Draw(Graphics& gfx, float dt)
{
	Vec2 Point0 = Vec2(GetX(), GetY());
	Vec2 Point1 = Vec2(GetX() + Width, GetY() + Height);
	Vec2 SrcPoint0 = Vec2(0, 0);
	Vec2 SrcPoint1 = Vec2(Width, Height);
	const RectF SourceRect = RectF(SrcPoint0, SrcPoint1);
	const RectF DestRect = RectF(Point0, Point1);
	MovementState->Draw(*this, gfx, dt, SourceRect, DestRect);
}

bool User::CheckIfAlive()
{
	if (Health <= 0)
	{
		IsAlive = false;
	}
	return IsAlive;
}

void User::TakeDamage(int DamageGiven)
{
	Health = Health - DamageGiven;
}

void User::Update(MainWindow &wnd)
{
	const float dt = usrft.Mark();
	MovementState->HandleInput(wnd, *this);
	MovementState->Move(dt, *this);
	CheckIfAlive();
	
}

float User::GetX() const
{
	return UserRect.left;
}

float User::GetY() const
{
	return UserRect.top;
}

float User::GetWidth() const
{
	return Width;
}

float User::GetHeight() const
{
	return Height;
}

RectF User::GetRect() const {
	return UserRect;
}

bool User::IsUserAlive() const
{
	return IsAlive;
}

float User::GetHealth() const
{
	return Health;
}

User::User(const float Given_left, const float Given_top)
{
	UserRect.left = Given_left;
	UserRect.top = Given_top;
}
