#pragma once

class MyVec2
{
public:
	MyVec2() = default;
	MyVec2(float x_in, float y_in);
	MyVec2 operator+(const MyVec2& rhs) const;
	MyVec2 operator-(const MyVec2& rhs) const;
	float GetX() const;
	float GetY() const;
public:
	float x;
	float y;
};

