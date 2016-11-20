#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(CPoint const& leftTop,
    double width, double height,
    std::string const& outlineColor, std::string const& fillColor)
    : m_leftTop(leftTop)
    , m_width(width)
    , m_height(height)
    , m_outlineColor(outlineColor)
    , m_fillColor(fillColor)
{
    m_rightBottom = CPoint(leftTop.x + width, leftTop.y + height);
}

double CRectangle::GetArea() const
{
    return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
    return (m_width + m_height) * 2;
}

std::string CRectangle::ToString() const
{
    return "Rectangle";
}

std::string CRectangle::GetOutlineColor() const
{
    return m_outlineColor;
}

std::string CRectangle::GetFillColor() const
{
    return m_fillColor;
}

CPoint const& CRectangle::GetLeftTop() const
{
    return m_leftTop;
}

CPoint const& CRectangle::GetRightBottom() const
{
    return m_rightBottom;
}

double CRectangle::GetWidth() const
{
    return m_width;
}

double CRectangle::GetHeight() const
{
    return m_height;
}