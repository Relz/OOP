#include "stdafx.h"
#include "color.h"
#include "Rectangle.h"

CRectangle::CRectangle(CPoint const& leftTop,
    float width, float height,
    std::string const& outlineColor, std::string const& fillColor)
    : CSolidShape("Rectangle", outlineColor, fillColor)
    , m_leftTop(leftTop)
    , m_width(width)
    , m_height(height)
{
}

float CRectangle::GetArea() const
{
    return m_width * m_height;
}

float CRectangle::GetPerimeter() const
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

float CRectangle::GetWidth() const
{
    return m_width;
}

float CRectangle::GetHeight() const
{
    return m_height;
}

void CRectangle::AppendProperties(std::ostream & strm) const
{
    strm << "  Perimeter = " << GetPerimeter() << "\n"
        << "  Left-Top point = " << GetLeftTop().ToString() << "\n"
        << "  Right-Bottom point = " << GetRightBottom().ToString() << "\n"
        << "  Width = " << GetWidth() << "\n"
        << "  Height = " << GetHeight() << "\n";
}

void CRectangle::Draw(ICanvas & canvas) const
{
    CPoint vertices[4] = 
    {
        m_leftTop,
        {m_leftTop.x + m_width, m_leftTop.y },
        { m_leftTop.x + m_width, m_leftTop.y + m_height },
        { m_leftTop.x, m_leftTop.y + m_height }
    };
    canvas.DrawLine(vertices[0], vertices[1], HexToRGB(GetOutlineColor()));
    canvas.DrawLine(vertices[1], vertices[2], HexToRGB(GetOutlineColor()));
    canvas.DrawLine(vertices[2], vertices[3], HexToRGB(GetOutlineColor()));
    canvas.DrawLine(vertices[3], vertices[0], HexToRGB(GetOutlineColor()));
    canvas.FillPolygon(vertices, HexToRGB(GetFillColor()));
}

bool operator >> (std::istream & in, std::shared_ptr<CRectangle> & rectangle)
{
    CPoint leftTop;
    float width;
    float height;
    std::string outlineColor;
    std::string fillColor;
    if (in >> leftTop && in >> width && in >> height && in >> outlineColor && in >> fillColor)
    {
        rectangle = std::make_shared<CRectangle>(leftTop, width, height, outlineColor, fillColor);
        return true;
    }
    return false;
}