#pragma once
#include "User.h"


void User::Draw(Graphics& gfx, float dt)
{
	Vec2 Point0 = Vec2(usrvec.GetX(), usrvec.GetY());
	Vec2 Point1 = Vec2(usrvec.GetX() + Width, usrvec.GetY() + Height);
	Vec2 SrcPoint0 = Vec2(0, 0);
	Vec2 SrcPoint1 = Vec2(float(Width), float(Height));
	const RectF SourceRect = RectF(SrcPoint0, SrcPoint1);
	const RectF DestRect = RectF(Point0, Point1);
	switch (Direction)
	{
	case DIRSTATE::NORTH:
		switch (StateOfMovement)
		{
		case MOVSTATE::STANDING:
			NorthStanding.Draw(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::SPRINTING:
			NorthSprintingAnimationHandler.Advance(dt);
			NorthSprintingAnimationHandler.Draw(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::FIGHTING:
			for (int TempX = int(usrvec.GetX()); TempX < int(usrvec.GetX()) + Width; TempX++)
			{
				for (int TempY = int(usrvec.GetY()); TempY < int(usrvec.GetY()) + Height; TempY++)
				{
					gfx.PutPixel(TempX, TempY, 255, 255, 255);
				}
			}
			break;
		}
		break;

	case DIRSTATE::SOUTH:
		switch (StateOfMovement)
		{
		case MOVSTATE::STANDING:
			SouthStanding.Draw(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::SPRINTING:
			SouthSprintingAnimationHandler.Advance(dt);
			SouthSprintingAnimationHandler.Draw(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::FIGHTING:
			for (int TempX = int(usrvec.GetX()); TempX < int(usrvec.GetX()) + Width; TempX++)
			{
				for (int TempY = int(usrvec.GetY()); TempY < int(usrvec.GetY()) + Height; TempY++)
				{
					gfx.PutPixel(TempX, TempY, 255, 255, 255);
				}
			}
			break;
		}
		break;

	case DIRSTATE::WEST:
		switch (StateOfMovement)
		{
		case MOVSTATE::STANDING:
			WestStanding.Draw(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::SPRINTING:
			WestSprintingAnimationHandler.Advance(dt);
			WestSprintingAnimationHandler.Draw(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::FIGHTING:
			for (int TempX = int(usrvec.GetX()); TempX < int(usrvec.GetX()) + Width; TempX++)
			{
				for (int TempY = int(usrvec.GetY()); TempY < int(usrvec.GetY()) + Height; TempY++)
				{
					gfx.PutPixel(TempX, TempY, 255, 255, 255);
				}
			}
			break;
		}
		break;

	case DIRSTATE::EAST:
		switch (StateOfMovement)
		{
		case MOVSTATE::STANDING:
			WestStanding.DrawReverse(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::SPRINTING:
			WestSprintingAnimationHandler.Advance(dt);
			WestSprintingAnimationHandler.DrawReverse(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::FIGHTING:
			for (int TempX = int(usrvec.GetX()); TempX < int(usrvec.GetX()) + Width; TempX++)
			{
				for (int TempY = int(usrvec.GetY()); TempY < int(usrvec.GetY()) + Height; TempY++)
				{
					gfx.PutPixel(TempX, TempY, 255, 255, 255);
				}
			}
			break;
		}
		break;

	case DIRSTATE::NORTHWEST:
		switch (StateOfMovement)
		{
		case MOVSTATE::STANDING:
			NorthWestStanding.Draw(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::SPRINTING:
			for (int TempX = int(usrvec.GetX()); TempX < int(usrvec.GetX()) + Width; TempX++)
			{
				for (int TempY = int(usrvec.GetY()); TempY < int(usrvec.GetY()) + Height; TempY++)
				{
					gfx.PutPixel(TempX, TempY, 255, 255, 255);
				}
			}
			break;
		case MOVSTATE::FIGHTING:
			for (int TempX = int(usrvec.GetX()); TempX < int(usrvec.GetX()) + Width; TempX++)
			{
				for (int TempY = int(usrvec.GetY()); TempY < int(usrvec.GetY()) + Height; TempY++)
				{
					gfx.PutPixel(TempX, TempY, 255, 255, 255);
				}
			}
			break;
		}
		break;

	case DIRSTATE::NORTHEAST:
		switch (StateOfMovement)
		{
		case MOVSTATE::STANDING:
			NorthWestStanding.DrawReverse(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::SPRINTING:
			for (int TempX = int(usrvec.GetX()); TempX < int(usrvec.GetX()) + Width; TempX++)
			{
				for (int TempY = int(usrvec.GetY()); TempY < int(usrvec.GetY()) + Height; TempY++)
				{
					gfx.PutPixel(TempX, TempY, 255, 255, 255);
				}
			}
			break;
		case MOVSTATE::FIGHTING:
			for (int TempX = int(usrvec.GetX()); TempX < int(usrvec.GetX()) + Width; TempX++)
			{
				for (int TempY = int(usrvec.GetY()); TempY < int(usrvec.GetY()) + Height; TempY++)
				{
					gfx.PutPixel(TempX, TempY, 255, 255, 255);
				}
			}
			break;
		}
		break;

	case DIRSTATE::SOUTHWEST:
		switch (StateOfMovement)
		{
		case MOVSTATE::STANDING:
			SouthWestStanding.Draw(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::SPRINTING:
			SouthWestSprintingAnimationHandler.Advance(dt);
			SouthWestSprintingAnimationHandler.Draw(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::FIGHTING:
			for (int TempX = int(usrvec.GetX()); TempX < int(usrvec.GetX()) + Width; TempX++)
			{
				for (int TempY = int(usrvec.GetY()); TempY < int(usrvec.GetY()) + Height; TempY++)
				{
					gfx.PutPixel(TempX, TempY, 255, 255, 255);
				}
			}
			break;
		}
		break;

	case DIRSTATE::SOUTHEAST:
		switch (StateOfMovement)
		{
		case MOVSTATE::STANDING:
			SouthWestStanding.DrawReverse(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::SPRINTING:
			SouthWestSprintingAnimationHandler.Advance(dt);
			SouthWestSprintingAnimationHandler.DrawReverse(SourceRect, DestRect, gfx);
			break;
		case MOVSTATE::FIGHTING:
			for (int TempX = int(usrvec.GetX()); TempX < int(usrvec.GetX()) + Width; TempX++)
			{
				for (int TempY = int(usrvec.GetY()); TempY < int(usrvec.GetY()) + Height; TempY++)
				{
					gfx.PutPixel(TempX, TempY, 255, 255, 255);
				}
			}
			break;
		}
		break;
	}
}

bool User::Move(MainWindow& wnd, float dt)
{
	bool IsMoving = false;
	if (wnd.kbd.KeyIsPressed('W'))
	{
		IsMoving = true;
		if (wnd.kbd.KeyIsPressed('A'))
		{
			Direction = DIRSTATE::NORTHWEST;
		}else
		if (wnd.kbd.KeyIsPressed('D')) {
			Direction = DIRSTATE::NORTHEAST;
		}else{
			Direction = DIRSTATE::NORTH;
		}
	}else
	if (wnd.kbd.KeyIsPressed('S')) {
		

		IsMoving = true;
		if (wnd.kbd.KeyIsPressed('A'))
		{
				Direction = DIRSTATE::SOUTHWEST;
		}else
		if (wnd.kbd.KeyIsPressed('D'))
		{
				Direction = DIRSTATE::SOUTHEAST;
		}
		else
		{
			Direction = DIRSTATE::SOUTH;
		}
	}else
	if (wnd.kbd.KeyIsPressed('A')) {
		Direction = DIRSTATE::WEST;
		IsMoving = true;
	}else
	if (wnd.kbd.KeyIsPressed('D')) {
		Direction = DIRSTATE::EAST;
		IsMoving = true;
	}
	if (!IsMoving)
	{
		StateOfMovement = MOVSTATE::STANDING;
		return false;

	}
	switch (Direction)
	{
	case DIRSTATE::NORTH:
		usrvec.y -= Speed * dt;
		break;
	case DIRSTATE::NORTHWEST:
		usrvec.x -= sqrtf(Speed * dt);
		usrvec.y -= sqrtf(Speed * dt);
		break;
	case DIRSTATE::NORTHEAST:
		usrvec.x += sqrtf(Speed * dt);
		usrvec.y -= sqrtf(Speed * dt);
		break;
	case DIRSTATE::SOUTH:
		usrvec.y += Speed * dt;
		break;
	case DIRSTATE::SOUTHWEST:
		usrvec.x -= sqrtf(Speed * dt);
		usrvec.y += sqrtf(Speed * dt);
		break;
	case DIRSTATE::SOUTHEAST:
		usrvec.x += sqrtf(Speed * dt);
		usrvec.y += sqrtf(Speed * dt);
		break;
	case DIRSTATE::WEST:
		usrvec.x -= Speed * dt;
		break;
	case DIRSTATE::EAST:
		usrvec.x += Speed * dt;
		break;
	}
	StateOfMovement = MOVSTATE::SPRINTING;
	return true;
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
	User::Move(wnd, dt);
	User::CheckIfAlive();
	
}

User::User(const float Given_x, const float Given_y)
{
	usrvec.x = Given_x;
	usrvec.y = Given_y;
}






