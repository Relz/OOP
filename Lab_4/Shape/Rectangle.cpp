#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(CPoint const& leftTop,
    double width, double height,
    std::string const& outlineColor, std::string const& fillColor)
    : CSolidShape(outlineColor, fillColor)
    , m_leftTop(leftTop)
    , m_width(width)
    , m_height(height)
{
}

double CRectangle::GetArea() const
{
    return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
    return (m_width + m_height) * 2;
}

CPoint const& CRectangle::GetLeftTop() const
{
    return m_leftTop;
}

CPoint const CRectangle::GetRightBottom() const
{
    return CPoint(m_leftTop.x + m_width, m_leftTop.y + m_height);
}

double CRectangle::GetWidth() const
{
    return m_width;
}

double CRectangle::GetHeight() const
{
    return m_height;
}

std::string CRectangle::ToString() const
{
    return (std::string("Type: Rectangle") + "\n"
        + "Area: " + std::to_string(GetArea()) + "\n"
        + "Perimeter: " + std::to_string(GetPerimeter()) + "\n"
        + "Outline color: " + GetOutlineColor() + "\n"
        + "Fill color: " + GetFillColor() + "\n"
        + "Left-Top point: " + GetLeftTop().ToString() + "\n"
        + "Right-Bottom point: " + GetRightBottom().ToString() + "\n"
        + "Width: " + std::to_string(GetWidth()) + "\n"
        + "Height: " + std::to_string(GetHeight()) + "\n");
}

bool operator >> (std::istream & in, std::shared_ptr<CRectangle> & rectangle)
{
    CPoint leftTop;
    double width;
    double height;
    std::string outlineColor;
    std::string fillColor;
    if (in >> leftTop && in >> width && in >> height && in >> outlineColor && in >> fillColor)
    {
        rectangle = std::make_shared<CRectangle>(leftTop, width, height, outlineColor, fillColor);
        return true;
    }
    return false;
}