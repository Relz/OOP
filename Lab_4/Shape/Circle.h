#pragma once
#include "Point.h"
#include "SolidShape.h"

class CCircle :
    public ISolidShape
{
public:
    CCircle(CPoint const& center, double radius, std::string const& outlineColor, std::string const& fillColor);
    ~CCircle() = default;
    double GetArea() const;
    double GetPerimeter() const;
    std::string ToString() const;
    std::string GetOutlineColor() const;
    std::string GetFillColor() const;
    CPoint const& GetCenter() const;
    double GetRadius() const;
private:
    CPoint m_center;
    double m_radius = 0;
    std::string m_outlineColor;
    std::string m_fillColor;
};

