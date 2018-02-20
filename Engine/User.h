#pragma once
#include "MyVec2.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"
#include "Frametimer.h"
#include "Sprite.h"
#include "AlphaSprite.h"
#include "AnimatedSprite.h"
#include <math.h>




class User
{
	//Data
private:

	constexpr static float Width = 60;
	constexpr static float Height = 100;

	RectF UserRect{ Graphics::ScreenWidth/2  , Graphics::ScreenHeight/ 2, Graphics::ScreenWidth / 2 + Width , Graphics::ScreenHeight/2 + Height };


	FrameTimer usrft;
	float Speed = 300;
	

	float Health = 100;
	bool IsAlive = true;

	//Functions
private:
	//Logic
	bool Move(MainWindow& wnd, float dt);
	bool CheckIfAlive();

public:
	void Draw(Graphics& gfx, float dt);
	void TakeDamage(int DamageGiven);
	void Update(MainWindow& kbd);

	//Getters
	float GetX() const;
	float GetY() const;
	float GetWidth() const;
	float GetHeight() const;
	bool IsUserAlive() const;
	float GetHealth() const;

	//Classes
	enum class DIRSTATE
	{
		WEST = 'A', EAST = 'D', NORTH = 'W', SOUTH = 'S', NORTHWEST = 'WA', NORTHEAST = 'WD', SOUTHWEST = 'SA', SOUTHEAST = 'SD'

	};
	enum class MOVSTATE {
		SPRINTING, FIGHTING, STANDING
	};


	DIRSTATE Direction = DIRSTATE::NORTH;
	MOVSTATE StateOfMovement = MOVSTATE::STANDING;
	
	/*static const StandingState stdstate;
	static const RunningState rngstate;
	UserState* StateOfMovement = *stdstate;*/
	// Graphics
private:

	AlphaSprite SouthStanding = AlphaSprite("Images/South/Alpha_Character_South_Standing.png");
	AlphaSprite WestStanding = AlphaSprite("Images/West/Alpha_Character_West_Standing.png");
	AlphaSprite NorthStanding = AlphaSprite("Images/North/Alpha_Character_North_Standing.png");
	AlphaSprite SouthWestStanding = AlphaSprite("Images/SouthWest/Alpha_Character_SouthWest_Standing.png");
	AlphaSprite NorthWestStanding = AlphaSprite("Images/NorthWest/Alpha_Character_NorthWest_Standing.png");

	Frames SouthSprintingAnim = Frames(Frames::SpriteType::Alpha, 2, "Images/South/Running/SouthRunning", ".png");
	AnimationController SouthSprintingAnimationHandler = AnimationController(50.f / Speed, SouthSprintingAnim);
	Frames NorthSprintingAnim = Frames(Frames::SpriteType::Alpha, 2, "Images/North/Running/NorthRunning", ".png");
	AnimationController NorthSprintingAnimationHandler = AnimationController(50.f / Speed, NorthSprintingAnim);
	Frames WestSprintingAnim = Frames(Frames::SpriteType::Alpha, 4, "Images/West/Running/WestRunning", ".png");
	AnimationController WestSprintingAnimationHandler = AnimationController(35.f / Speed, WestSprintingAnim);
	Frames SouthWestSprintingAnim = Frames(Frames::SpriteType::Alpha, 4, "Images/SouthWest/Running/SouthWestRunning", ".png");
	AnimationController SouthWestSprintingAnimationHandler = AnimationController(40.f / Speed, SouthWestSprintingAnim);

	
public:
	User() = default;
	User(const float Given_x, const float Given_y);
	//Statemachine (in progress, not implemented
	class UserState
	{
		virtual void Update(float dt, MainWindow& wnd, User& user) = 0;
		virtual void Draw(const User& user) {};
		virtual void Move(float dt, User& user ) {};
		virtual void HandleInput(MainWindow& wnd , User& user ) {};
		//Roses are red
		//Violets are blue
		//If you are reading this
		//I feel sorry for you


	};

	class RunningState : UserState
	{
		virtual void Update(float dt, MainWindow& wnd, User& user)
		{
			HandleInput(wnd, user);
			Move(dt, user);

		};
		virtual void HandleInput(MainWindow& wnd, User& user )
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
							user.StateOfMovement = User::MOVSTATE::STANDING;
						}
		}
		virtual void Move(float dt, User& user)
		{
			switch (user.Direction)
			{
			case User::DIRSTATE::NORTH:
				
				break;
			case User::DIRSTATE::NORTHWEST:
				
				break;
			case User::DIRSTATE::NORTHEAST:
				
				break;
			case User::DIRSTATE::SOUTH:
				
				break;
			case User::DIRSTATE::SOUTHWEST:
				
				break;
			case User::DIRSTATE::SOUTHEAST:
				
				break;
			case User::DIRSTATE::WEST:
				
				break;
			case User::DIRSTATE::EAST:
				
				break;
			};
		}

	};

	class StandingState : UserState
	{
		virtual void Update(float dt,  MainWindow& wnd, User& user)
		{
			HandleInput(wnd, user);
			Move(dt, user);
		}
		virtual void HandleInput(MainWindow& wnd, User& user)
		{
			if (wnd.kbd.KeyIsPressed('W'))
			{
				if (wnd.kbd.KeyIsPressed('A'))
				{
					user.Direction = User::DIRSTATE::NORTHWEST;
				}
				else
					if (wnd.kbd.KeyIsPressed('D')) {
						user.Direction = User::DIRSTATE::NORTHEAST;
					}
					else {
						user.Direction = User::DIRSTATE::NORTH;
					}
			}
			else
				if (wnd.kbd.KeyIsPressed('S')) {



					if (wnd.kbd.KeyIsPressed('A'))
					{
						user.Direction = User::DIRSTATE::SOUTHWEST;
					}
					else
						if (wnd.kbd.KeyIsPressed('D'))
						{
							user.Direction = User::DIRSTATE::SOUTHEAST;
						}
						else
						{
							user.Direction = User::DIRSTATE::SOUTH;
						}
				}
				else
					if (wnd.kbd.KeyIsPressed('A')) {
						user.Direction = User::DIRSTATE::WEST;
					}
					else
						if (wnd.kbd.KeyIsPressed('D')) {
							user.Direction = User::DIRSTATE::EAST;

						}
						else
						{
							//add changing modes
						}
		}
		virtual void Move(float dt, User& user)
		{

		}

	};



};



