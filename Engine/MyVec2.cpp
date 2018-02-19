#pragma once
#include "MyVec2.h"
#include <cmath>

MyVec2::MyVec2(float x_in, float y_in)
{
	x = x_in;
	y = y_in;
}

MyVec2 MyVec2::operator+(const MyVec2 & rhs) const
{
	return MyVec2(x + rhs.x, y + rhs.y);
}

MyVec2 & MyVec2::operator+=(const MyVec2 & rhs)
{
	return *this = *this + rhs;
}

MyVec2 MyVec2::operator-(const MyVec2 & rhs) const
{
	return MyVec2(x - rhs.x, y - rhs.y);
}

MyVec2 & MyVec2::operator-=(const MyVec2 & rhs)
{
	return *this = *this - rhs;
}

MyVec2 MyVec2::operator*(float scalar) const
{
	return MyVec2(x * scalar, y * scalar );
}

MyVec2 & MyVec2::operator*=(const float rhs)
{
	return *this = *this * rhs;
}

float MyVec2::GetX() const
{
	return x;
}

float MyVec2::GetY() const
{
	return y;
}

float MyVec2::GetLength() const
{
	return std::sqrt(GetLengthSq());
}

float MyVec2::GetLengthSq() const
{
	return x*x + y*y;
}

MyVec2& MyVec2::Normalize()
{
	return *this = GetNormalized();
}
MyVec2 MyVec2::GetNormalized()
{
	const float length = GetLength();
	if (length == 0.0f)
	{
		return *this;
	}
	else
	{
	return *this * (1.0f / length);
	}
}


