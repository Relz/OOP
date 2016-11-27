#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(CPoint const& center, double radius, std::string const& outlineColor, std::string const& fillColor)
    : CSolidShape(fillColor)
    , m_center(center)
    , m_radius(radius)
    , m_outlineColor(outlineColor)
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

std::string CCircle::GetOutlineColor() const
{
    return m_outlineColor;
}

CPoint const& CCircle::GetCenter() const
{
    return m_center;
}

double CCircle::GetRadius() const
{
    return m_radius;
}

std::string CCircle::ToString() const
{
    return (std::string("Type: Circle") + "\n"
        + "Area: " + std::to_string(GetArea()) + "\n"
        + "Circumference: " + std::to_string(GetPerimeter()) + "\n"
        + "Outline color: " + GetOutlineColor() + "\n"
        + "Fill color: " + GetFillColor() + "\n"
        + "Center point: " + GetCenter().ToString() + "\n"
        + "Radius: " + std::to_string(GetRadius()) + "\n");
}