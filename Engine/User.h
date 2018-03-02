#pragma once
#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"
#include "Frametimer.h"
#include "Sprite.h"
#include "AlphaSprite.h"
#include "AnimatedSprite.h"
#include <math.h>


//DONT FORGET TO MAKE SPRITES 120X70 IN THE FUTURE

class User
{
	//**********************************//
	//             Data                 //
private:

	constexpr static float Width = 60;
	constexpr static float Height = 100;
	RectF UserRect{ Graphics::ScreenWidth/2  , Graphics::ScreenHeight/ 2, Graphics::ScreenWidth / 2 + Width , Graphics::ScreenHeight/2 + Height };


	FrameTimer usrft;
	float Speed = 300;
	

	float Health = 100;
	float DamageAmount = 50;
	bool IsAlive = true;

	//**********************************//
	//           Functions              //
private:
	//Logic
	bool CheckIfAlive();

public:
	User() = default;
	User(const float Given_x, const float Given_y);
	void Draw(Graphics& gfx, float dt);
	void TakeDamage(int DamageGiven);
	void Update(MainWindow& kbd);

	//Getters
	float GetX() const;
	float GetY() const;
	float GetWidth() const;
	float GetHeight() const;
	RectF GetRect() const;
	bool IsUserAlive() const;
	float GetHealth() const;
	float GetDamageAmount() const;

	
	
	
	//**********************************//
	//           Graphics               //
private:

	AlphaSprite SouthStanding = AlphaSprite("Images/South/Alpha_Character_South_Standing.png");
	AlphaSprite WestStanding = AlphaSprite("Images/West/Alpha_Character_West_Standing.png");
	AlphaSprite NorthStanding = AlphaSprite("Images/North/Alpha_Character_North_Standing.png");
	
	Frames SouthSprintingAnim = Frames(Frames::SpriteType::Alpha, 2, "Images/South/Running/SouthRunning", ".png");
	AnimationController SouthSprintingAnimationHandler = AnimationController(50.f / Speed, SouthSprintingAnim);
	Frames NorthSprintingAnim = Frames(Frames::SpriteType::Alpha, 2, "Images/North/Running/NorthRunning", ".png");
	AnimationController NorthSprintingAnimationHandler = AnimationController(50.f / Speed, NorthSprintingAnim);
	Frames WestSprintingAnim = Frames(Frames::SpriteType::Alpha, 4, "Images/West/Running/WestRunning", ".png");
	AnimationController WestSprintingAnimationHandler = AnimationController(35.f / Speed, WestSprintingAnim);


	
public:
	
	//Classes
	enum class DIRSTATE
	{
		WEST = 'A', EAST = 'D', NORTH = 'W', SOUTH = 'S', NORTHWEST = 'WA', NORTHEAST = 'WD', SOUTHWEST = 'SA', SOUTHEAST = 'SD'

	};
	DIRSTATE Direction = DIRSTATE::NORTH;
	class UserState
	{
	public:
		virtual void Draw(User& user, Graphics& gfx, float const dt, RectF SourceRect, RectF DestRect) {};
		virtual void Move(float dt, User& user) {};
		virtual void HandleInput(MainWindow& wnd, User& user) {};

		//Roses are red
		//Violets are blue
		//If you are reading this
		//I feel sorry for you
	};
	class RunningState : public UserState
	{
	public:

		void HandleInput(MainWindow& wnd, User& user)
		{
			if (wnd.kbd.KeyIsPressed('W'))
			{
				if (wnd.kbd.KeyIsPressed('A'))
				{
					user.Direction = DIRSTATE::NORTHWEST;
				}
				else
					if (wnd.kbd.KeyIsPressed('D')) {
						user.Direction = DIRSTATE::NORTHEAST;
					}
					else {
						user.Direction = DIRSTATE::NORTH;

					}
			}
			else
				if (wnd.kbd.KeyIsPressed('S'))
				{
					if (wnd.kbd.KeyIsPressed('A'))
					{
						user.Direction = DIRSTATE::SOUTHWEST;
					}
					else
						if (wnd.kbd.KeyIsPressed('D'))
						{
							user.Direction = DIRSTATE::SOUTHEAST;
						}
						else
						{
							user.Direction = DIRSTATE::SOUTH;
						}
				}
				else
					if (wnd.kbd.KeyIsPressed('A')) {
						user.Direction = DIRSTATE::WEST;
					}
					else
						if (wnd.kbd.KeyIsPressed('D')) {
							user.Direction = DIRSTATE::EAST;
						}
						else
						{
							user.MovementState = &user.standingstate;
						}
		}
		void Move(float dt, User& user)
		{
			constexpr static float Sqrtof2 = 1.41421356237f;
			const float velocity = user.Speed * dt;
			const float velocityindiagonals = user.Speed * dt / Sqrtof2;
			switch (user.Direction)
			{
			case DIRSTATE::NORTH:
				user.UserRect.top -= velocity;
				user.UserRect.bottom -= velocity;
				break;
			case DIRSTATE::NORTHWEST:
				user.UserRect.top -= velocityindiagonals;
				user.UserRect.bottom -= velocityindiagonals;
				user.UserRect.left -= velocityindiagonals;
				user.UserRect.right -= velocityindiagonals;
				break;
			case DIRSTATE::NORTHEAST:
				user.UserRect.top -= velocityindiagonals;
				user.UserRect.bottom -= velocityindiagonals;
				user.UserRect.left += velocityindiagonals;
				user.UserRect.right += velocityindiagonals;
				break;
			case DIRSTATE::SOUTH:
				user.UserRect.top += velocity;
				user.UserRect.bottom += velocity;
				break;
			case DIRSTATE::SOUTHWEST:
				user.UserRect.top += velocityindiagonals;
				user.UserRect.bottom += velocityindiagonals;
				user.UserRect.left -= velocityindiagonals;
				user.UserRect.right -= velocityindiagonals;

				break;
			case DIRSTATE::SOUTHEAST:
				user.UserRect.top += velocityindiagonals;
				user.UserRect.bottom += velocityindiagonals;
				user.UserRect.left += velocityindiagonals;
				user.UserRect.right += velocityindiagonals;
				break;
			case DIRSTATE::WEST:
				user.UserRect.left -= velocity;
				user.UserRect.right -= velocity;
				break;
			case DIRSTATE::EAST:
				user.UserRect.left += velocity;
				user.UserRect.right += velocity;
				break;
			}
		}
		void Draw(User& user, Graphics& gfx, float const dt, RectF SourceRect, RectF DestRect) 
		{
			switch (user.Direction)
			{
			case DIRSTATE::NORTH:
				user.NorthSprintingAnimationHandler.Advance(dt);
				user.NorthSprintingAnimationHandler.Draw(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::NORTHEAST:
				user.WestSprintingAnimationHandler.Advance(dt);
				user.WestSprintingAnimationHandler.DrawReverse(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::EAST:
				user.WestSprintingAnimationHandler.Advance(dt);
				user.WestSprintingAnimationHandler.DrawReverse(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::SOUTHEAST:
				user.WestSprintingAnimationHandler.Advance(dt);
				user.WestSprintingAnimationHandler.DrawReverse(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::SOUTH:
				user.SouthSprintingAnimationHandler.Advance(dt);
				user.SouthSprintingAnimationHandler.Draw(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::SOUTHWEST:
				user.WestSprintingAnimationHandler.Advance(dt);
				user.WestSprintingAnimationHandler.Draw(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::WEST:
				user.WestSprintingAnimationHandler.Advance(dt);
				user.WestSprintingAnimationHandler.Draw(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::NORTHWEST:
				user.WestSprintingAnimationHandler.Advance(dt);
				user.WestSprintingAnimationHandler.Draw(SourceRect, DestRect, gfx);
				break;
			}
		};
	};
	class StandingState : public UserState
	{
	public:
		void HandleInput(MainWindow& wnd, User& user)
		{
			if (wnd.kbd.KeyIsPressed('W'))
			{
				user.MovementState = &user.runningstate;
				if (wnd.kbd.KeyIsPressed('A'))
				{
					user.Direction = DIRSTATE::NORTHWEST;
				}
				else
					if (wnd.kbd.KeyIsPressed('D')) {
						user.Direction = DIRSTATE::NORTHEAST;
					}
					else {
						user.Direction = DIRSTATE::NORTH;
					}
			}
			else
				if (wnd.kbd.KeyIsPressed('S')) {
					user.MovementState = &user.runningstate;
					if (wnd.kbd.KeyIsPressed('A'))
					{
						user.Direction = DIRSTATE::SOUTHWEST;
					}
					else
						if (wnd.kbd.KeyIsPressed('D'))
						{
							user.Direction = DIRSTATE::SOUTHEAST;
						}
						else
						{
							user.Direction = DIRSTATE::SOUTH;
						}
				}
				else
					if (wnd.kbd.KeyIsPressed('A')) {
						user.MovementState = &user.runningstate;
						user.Direction = DIRSTATE::WEST;
					}
					else
						if (wnd.kbd.KeyIsPressed('D')) {
							user.MovementState = &user.runningstate;
							user.Direction = DIRSTATE::EAST;
						}
						else
						{
						}
		}
		void Move(float dt, User& user)
		{

		}
		void Draw(User& user, Graphics& gfx, float const dt, RectF SourceRect, RectF DestRect) 
		{
			switch (user.Direction)
			{
			case DIRSTATE::NORTH:
				user.NorthStanding.Draw(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::NORTHEAST:
				user.WestStanding.DrawReverse(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::EAST:
				user.WestStanding.DrawReverse(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::SOUTHEAST:
				user.WestStanding.DrawReverse(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::SOUTH:
				user.SouthStanding.Draw(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::SOUTHWEST:
				user.WestStanding.Draw(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::WEST:
				user.WestStanding.Draw(SourceRect, DestRect, gfx);
				break;
			case DIRSTATE::NORTHWEST:
				user.WestStanding.Draw(SourceRect, DestRect, gfx);
			}
		};
	};
	StandingState standingstate;
	RunningState runningstate;
	UserState* MovementState = &standingstate ;
};

