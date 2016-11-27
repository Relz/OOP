#include "stdafx.h"
#include "Triangle.h"

bool AreVerticesEquals(CPoint const& vertex1, CPoint const& vertex2)
{
    return (vertex1.x == vertex2.x && vertex1.y == vertex2.y);
}

bool AreValidTriangleVertices(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3)
{
    return (!AreVerticesEquals(vertex1, vertex2)
         && !AreVerticesEquals(vertex2, vertex3)
         && !AreVerticesEquals(vertex3, vertex1));
}

CTriangle::CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3,
                     std::string const& outlineColor, std::string const& fillColor)
    : CSolidShape(fillColor)
    , m_outlineColor(outlineColor)
{
    if (!AreValidTriangleVertices(vertex1, vertex2, vertex3))
    {
        throw std::invalid_argument("Vertices can't be in one point");
    }
    m_vertices[0] = vertex1;
    m_vertices[1] = vertex2;
    m_vertices[2] = vertex3;
}

double CTriangle::GetSideLength(CPoint const& vertex1, CPoint const& vertex2) const
{
    return std::hypot(vertex2.x - vertex1.x, vertex2.y - vertex1.y);
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

std::string CTriangle::GetOutlineColor() const
{
    return m_outlineColor;
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

std::string CTriangle::ToString() const
{
    return (std::string("Type: Triangle") + "\n"
        + "Area: " + std::to_string(GetArea()) + "\n"
        + "Perimeter: " + std::to_string(GetPerimeter()) + "\n"
        + "Outline color: " + GetOutlineColor() + "\n"
        + "Fill color: " + GetFillColor() + "\n"
        + "Vertex 1: " + GetVertex1().ToString() + "\n"
        + "Vertex 2: " + GetVertex2().ToString() + "\n"
        + "Vertex 3: " + GetVertex3().ToString() + "\n"
        + "Side length 1: " + std::to_string(GetSideLength(GetVertex1(), GetVertex2())) + "\n"
        + "Side length 2: " + std::to_string(GetSideLength(GetVertex2(), GetVertex3())) + "\n"
        + "Side length 3: " + std::to_string(GetSideLength(GetVertex3(), GetVertex1())) + "\n");
}