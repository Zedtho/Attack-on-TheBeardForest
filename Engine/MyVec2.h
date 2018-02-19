#pragma once

class MyVec2
{
public:
	MyVec2() = default;
	MyVec2(float x_in, float y_in);
	MyVec2 operator+(const MyVec2& rhs) const;
	MyVec2& operator+=(const MyVec2& rhs);
	MyVec2 operator-(const MyVec2& rhs) const;
	MyVec2 & operator-=(const MyVec2& rhs);
	MyVec2 operator*(float rhs) const;
	MyVec2& operator*=(const float rhs);
	float GetX() const;
	float GetY() const;
	float GetLength() const;
	float GetLengthSq() const;
	MyVec2 GetNormalized();
	MyVec2& Normalize();
public:
	float x;
	float y;
};

