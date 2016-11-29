#include "stdafx.h"
#include "color.h"
#include "Circle.h"

CCircle::CCircle(CPoint const& center, double radius, std::string const& outlineColor, std::string const& fillColor)
    : CSolidShape("Circle", outlineColor, fillColor)
    , m_center(center)
    , m_radius(radius)
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

CPoint const& CCircle::GetCenter() const
{
    return m_center;
}

double CCircle::GetRadius() const
{
    return m_radius;
}

void CCircle::AppendProperties(std::ostream & strm) const
{
    strm << "  Circumference = " << GetPerimeter() << "\n"
        << "  Center point = " << GetCenter().ToString() << "\n"
        << "  Radius = " << GetRadius() << "\n";
}

void CCircle::Draw(ICanvas & canvas) const
{
    canvas.FillCircle(m_center, m_radius, HexToRGB(GetFillColor()));
    canvas.DrawCircle(m_center, m_radius, HexToRGB(GetOutlineColor()));
}

bool operator >> (std::istream & in, std::shared_ptr<CCircle> & circle)
{
    CPoint center;
    double radius;
    std::string outlineColor;
    std::string fillColor;
    if (in >> center && in >> radius && in >> outlineColor && in >> fillColor)
    {
        circle = std::make_shared<CCircle>(center, radius, outlineColor, fillColor);
        return true;
    }
    return false;
}