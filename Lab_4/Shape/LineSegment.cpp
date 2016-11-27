#include "stdafx.h"
#include "LineSegment.h"

CLineSegment::CLineSegment(CPoint const& startPoint, CPoint const& endPoint, std::string const& outlineColor)
    : CShape(outlineColor)
    , m_startPoint(startPoint)
    , m_endPoint(endPoint)
{
}

double CLineSegment::GetArea() const
{
    return 0;
}

double CLineSegment::GetPerimeter() const
{
    return std::hypot(m_endPoint.x - m_startPoint.x, m_endPoint.y - m_startPoint.y);
}

CPoint const& CLineSegment::GetStartPoint() const
{
    return m_startPoint;
}

CPoint const& CLineSegment::GetEndPoint() const
{
    return m_endPoint;
}

std::string CLineSegment::ToString() const
{
    return (std::string("Type: Line") + "\n"
        + "Area: " + std::to_string(GetArea()) + "\n"
        + "Perimeter: " + std::to_string(GetPerimeter()) + "\n"
        + "Outline color: " + GetOutlineColor() + "\n"
        + "Start point: " + GetStartPoint().ToString() + "\n"
        + "End point: " + GetEndPoint().ToString() + "\n");
}