#include "RectF.h"

RectF::RectF(const float in_left, const float in_right, const float in_top, const float in_bottom)
{
	left = in_left;
	right = in_right;
	top = in_top;
	bottom = in_bottom;
}

RectF::RectF(const MyVec2& TopLeft, const MyVec2& BottomRight)
{
	RectF(TopLeft.GetX(), BottomRight.GetX(), TopLeft.GetY(), BottomRight.GetY());
}

RectF::RectF(const MyVec2& TopLeft, const float Width, const float Height)
{
	RectF(TopLeft.GetX(), TopLeft.GetX() + Width, TopLeft.GetY(), TopLeft.GetY() + Height);
}

RectF RectF::FromCenter(const MyVec2 & Center, float HalfWidth, float HalfHeight)
{
	return RectF(Center.GetX() - HalfWidth, Center.GetX() + HalfWidth, Center.GetY() - HalfHeight, Center.GetY() + HalfHeight);
}

bool RectF::IsOverlappingWith(const RectF & other) const
{
	return left < other.right && right > other.left && top < other.bottom && bottom > other.top;
}


