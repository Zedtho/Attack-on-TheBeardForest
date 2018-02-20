#pragma once
#include "MyVec2.h"
class RectF
{
	float left;
	float right;
	float top;
	float bottom;
	RectF() = default;
	RectF(const float in_left, const float in_right, const float in_top, const float in_bottom);
	RectF(const MyVec2& TopLeft, const MyVec2& BottomRight);
	RectF(const MyVec2& TopLeft, const float Width, const float Height);
	static RectF FromCenter(const MyVec2& Center, float HalfWidth, float HalfHeight);
	bool IsOverlappingWith(const RectF& other) const;
};