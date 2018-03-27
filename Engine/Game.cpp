/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	enty(300, 400, 5)

	
	
{
	Entities.push_back(enty);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = DrawFt.Mark();
	// AI
	TestForCollisions(user, Entities);
	HandleDeaths(user, Entities);
		
	// Physics
	user.Update(wnd);
	for (int i = 0; i < Entities.size; i++)
	{
		Entities[i].Move(dt, user.GetRect() );
	}
}

void Game::ComposeFrame()
{
	const float dt = DrawFt.Mark();
	for (int Index = 0; Index < Entities.size(); Index++)
	{
		Entities[Index].Draw(gfx);
	}
	user.Draw(gfx, dt);

}

void Game::TestForCollisions(User& user, std::vector<Entity>& Entities)
{
	for (int i = 0; i < Entities.size(); i++)
	{
		if (user.GetRect().Overlaps(Entities[i].GetRect())
			&& wnd.mouse.LeftIsPressed()
			)
		{
			Entities[i].TakeDamage(user.GetDamageAmount());
		}
	}
}

void Game::HandleDeaths(const User& user, std::vector<Entity>& Entities)
{
	if (!user.IsUserAlive())
	{
		GameOver = true;
	}
	for (int Index = 0; Index < Entities.size(); Index++)
	{
		Entities[Index].CheckIfDead();
	}

}