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

bool operator >> (std::istream & in, CPoint & point)
{
    if (in >> point.x && in >> point.y)
    {
        return true;
    }
    return false;
}