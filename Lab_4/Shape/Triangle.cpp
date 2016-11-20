#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(CPoint const& firstVertex, CPoint const& secondVertex, CPoint const& thirdVertex,
                     std::string const& outlineColor, std::string const& fillColor)
    : m_outlineColor(outlineColor)
    , m_fillColor(fillColor)
{
    m_vertices[0] = firstVertex;
    m_vertices[1] = secondVertex;
    m_vertices[2] = thirdVertex;
}

double CTriangle::GetSideLength(CPoint const& firstVertex, CPoint const& secondVertex) const
{
    return std::hypot(secondVertex.x - firstVertex.x, secondVertex.y - firstVertex.y);
}

double CTriangle::GetArea() const
{
    double semiperimeter = GetPerimeter() / 2;
    return std::sqrt(semiperimeter *
        (semiperimeter - GetSideLength(m_vertices[0], m_vertices[1])) *
        (semiperimeter - GetSideLength(m_vertices[1], m_vertices[2])) *
        (semiperimeter - GetSideLength(m_vertices[2], m_vertices[0]))
    );
}

double CTriangle::GetPerimeter() const
{
    return GetSideLength(m_vertices[0], m_vertices[1]) +
        GetSideLength(m_vertices[1], m_vertices[2]) +
        GetSideLength(m_vertices[2], m_vertices[0]);
}

std::string CTriangle::ToString() const
{
    return "Triangle";
}

std::string CTriangle::GetOutlineColor() const
{
    return m_outlineColor;
}

std::string CTriangle::GetFillColor() const
{
    return m_fillColor;
}

CPoint const& CTriangle::GetVertex1() const
{
    return m_vertices[0];
}

CPoint const& CTriangle::GetVertex2() const
{
    return m_vertices[1];
}

CPoint const& CTriangle::GetVertex3() const
{
    return m_vertices[2];
}