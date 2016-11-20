#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(CPoint const& center, double radius, std::string const& outlineColor, std::string const& fillColor)
    : ISolidShape()
    , m_center(center)
    , m_radius(radius)
    , m_outlineColor(outlineColor)
    , m_fillColor(fillColor)
{
}

double CCircle::GetArea() const
{
    return M_PI * std::pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
    return 2 * M_PI * m_radius;
}

std::string CCircle::ToString() const
{
    return "CCircle";
}

std::string CCircle::GetOutlineColor() const
{
    return m_outlineColor;
}

std::string CCircle::GetFillColor() const
{
    return m_fillColor;
}

CPoint const& CCircle::GetCenter() const
{
    return m_center;
}

double CCircle::GetRadius() const
{
    return m_radius;
}