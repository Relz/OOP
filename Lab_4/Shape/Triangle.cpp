#include "stdafx.h"
#include "Color.h"
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
    : CSolidShape("Triangle", outlineColor, fillColor)
{
    if (!AreValidTriangleVertices(vertex1, vertex2, vertex3))
    {
        throw std::invalid_argument("Vertices can't be in one point");
    }
    m_vertices.push_back(vertex1);
    m_vertices.push_back(vertex2);
    m_vertices.push_back(vertex3);
}

float CTriangle::GetSideLength(CPoint const& vertex1, CPoint const& vertex2) const
{
    return std::hypot(vertex2.x - vertex1.x, vertex2.y - vertex1.y);
}

float CTriangle::GetArea() const
{
    float semiperimeter = GetPerimeter() / 2;
    return std::sqrt(semiperimeter *
        (semiperimeter - GetSideLength(m_vertices[0], m_vertices[1])) *
        (semiperimeter - GetSideLength(m_vertices[1], m_vertices[2])) *
        (semiperimeter - GetSideLength(m_vertices[2], m_vertices[0]))
    );
}

float CTriangle::GetPerimeter() const
{
    return GetSideLength(m_vertices[0], m_vertices[1]) +
        GetSideLength(m_vertices[1], m_vertices[2]) +
        GetSideLength(m_vertices[2], m_vertices[0]);
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

void CTriangle::AppendPropertiesSolid(std::ostream & strm) const
{
    strm << "  Perimeter = " << GetPerimeter() << "\n"
        << "  Vertex 1 = " << GetVertex1().ToString() << "\n"
        << "  Vertex 2 = " << GetVertex2().ToString() << "\n"
        << "  Vertex 3 = " << GetVertex3().ToString() << "\n"
        << "  Side length 1 = " << GetSideLength(GetVertex1(), GetVertex2()) << "\n"
        << "  Side length 2 = " << GetSideLength(GetVertex2(), GetVertex3()) << "\n"
        << "  Side length 3 = " << GetSideLength(GetVertex3(), GetVertex1()) << "\n";
}

void CTriangle::Draw(ICanvas & canvas) const
{
    canvas.FillPolygon(m_vertices, HexToRGB(GetFillColor()));
    canvas.DrawLine(m_vertices[0], m_vertices[1], HexToRGB(GetOutlineColor()));
    canvas.DrawLine(m_vertices[1], m_vertices[2], HexToRGB(GetOutlineColor()));
    canvas.DrawLine(m_vertices[2], m_vertices[0], HexToRGB(GetOutlineColor()));
}

bool operator >> (std::istream & in, std::shared_ptr<CTriangle> & triangle)
{
    CPoint vertex1;
    CPoint vertex2;
    CPoint vertex3;
    std::string outlineColor;
    std::string fillColor;
    if (in >> vertex1 && in >> vertex2 && in >> vertex3 && in >> outlineColor && in >> fillColor
        && outlineColor.length() == 6 && fillColor.length() == 6)
    {
        triangle = std::make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
        return true;
    }
    return false;
}