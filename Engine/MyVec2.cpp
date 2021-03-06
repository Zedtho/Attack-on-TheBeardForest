#pragma once
#include "MyVec2.h"

MyVec2::MyVec2(float x_in, float y_in)
{
	x = x_in;
	y = y_in;
}

MyVec2 MyVec2::operator+(const MyVec2 & rhs) const
{
	return MyVec2(x + rhs.x, y + rhs.y);
}

MyVec2 MyVec2::operator-(const MyVec2 & rhs) const
{
	return MyVec2(x - rhs.x, y - rhs.y);
}

float MyVec2::GetX() const
{
	return x;
}

float MyVec2::GetY() const
{
	return y;
}


