#include "stdafx.h"
#include "Point.h"

CPoint::CPoint(double x, double y)
    : x(x)
    , y(y)
{
}

std::string CPoint::ToString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}