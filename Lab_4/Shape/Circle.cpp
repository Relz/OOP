#include "stdafx.h"
#include "Color.h"
#include "Circle.h"

CCircle::CCircle(CPoint const& center, float radius, std::string const& outlineColor, std::string const& fillColor)
    : CSolidShape("Circle", outlineColor, fillColor)
    , m_center(center)
    , m_radius(radius)
{
}

float CCircle::GetArea() const
{
    return boost::math::constants::pi<float>() * std::pow(m_radius, 2);
}

float CCircle::GetPerimeter() const
{
    return 2 * boost::math::constants::pi<float>() * m_radius;
}

CPoint const& CCircle::GetCenter() const
{
    return m_center;
}

float CCircle::GetRadius() const
{
    return m_radius;
}

void CCircle::AppendPropertiesSolid(std::ostream & strm) const
{
    strm << "  Circumference = " << GetPerimeter() << "\n"
        << "  Center point = " << GetCenter().ToString() << "\n"
        << "  Radius = " << GetRadius() << "\n";
}

void CCircle::Draw(ICanvas & canvas) const
{
    canvas.DrawCircle(m_center, m_radius, HexToRGB(GetOutlineColor()));
    canvas.FillCircle(m_center, m_radius, HexToRGB(GetFillColor()));
}

bool operator >> (std::istream & in, std::shared_ptr<CCircle> & circle)
{
    CPoint center;
    float radius;
    std::string outlineColor;
    std::string fillColor;
    if (in >> center && in >> radius && in >> outlineColor && in >> fillColor && outlineColor.length() == 6 && fillColor.length() == 6)
    {
        circle = std::make_shared<CCircle>(center, radius, outlineColor, fillColor);
        return true;
    }
    return false;
}