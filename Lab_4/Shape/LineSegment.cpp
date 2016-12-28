#include "stdafx.h"
#include "Color.h"
#include "LineSegment.h"

CLineSegment::CLineSegment(CPoint const& startPoint, CPoint const& endPoint, std::string const& outlineColor)
    : CShape("Line", outlineColor)
    , m_startPoint(startPoint)
    , m_endPoint(endPoint)
{
}

float CLineSegment::GetArea() const
{
    return 0;
}

float CLineSegment::GetPerimeter() const
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

void CLineSegment::AppendProperties(std::ostream & strm) const
{
    strm << "  Perimeter = " << GetPerimeter() << "\n"
        << "  Start point = " << GetStartPoint().ToString() << "\n"
        << "  End point = " << GetEndPoint().ToString() << "\n";
}

void CLineSegment::Draw(ICanvas & canvas) const
{
    canvas.DrawLine(m_startPoint, m_endPoint, HexToRGB(GetOutlineColor()));
}

bool operator >> (std::istream & in, std::shared_ptr<CLineSegment> & line)
{
    CPoint startPoint;
    CPoint endPoint;
    std::string outlineColor;
    if (in >> startPoint && in >> endPoint && in >> outlineColor && outlineColor.length() == 6)
    {
        line = std::make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
        return true;
    }
    return false;
}