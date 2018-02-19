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
	PossiblyDamage(usr, Entities);
	usr.Update(wnd);
	HandleDeaths(usr, Entities);
		if(HasNotHappened)
		{
			Entities.push_back(enty);
			HasNotHappened = false;
		}
}

void Game::ComposeFrame()
{
	const float dt = DrawFt.Mark();
	for (int Index = 0; Index < Entities.size(); Index++)
	{
		
		Entities[Index].Draw(gfx);
	}
	usr.Draw(gfx, dt);

}

void Game::PossiblyDamage(User& usr, std::vector<Entity>& Entities)
{
	for (int Index = 0; Index < Entities.size(); Index++)
	{
		if (Entities[Index].entityvec.GetX() + Entities[Index].Width > usr.GetX()
			&& Entities[Index].entityvec.GetX() < usr.GetX() + usr.GetWidth()
			&& Entities[Index].entityvec.GetY() < usr.GetY() + usr.GetHeight()
			&& Entities[Index].entityvec.GetY() + Entities[Index].Height > usr.GetY()
			&& wnd.mouse.LeftIsPressed()
			)
		{
			Entities[Index].TakeDamage(2);
		}
	}
}

void Game::HandleDeaths(const User& usr, std::vector<Entity>& Entities)
{
	if (usr.IsUserAlive() == false)
	{
		GameOver = true;
	}
	for (int Index = 0; Index < Entities.size(); Index++)
	{
		Entities[Index].CheckIfDead();

	}

}