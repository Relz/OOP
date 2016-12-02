#include "stdafx.h"
#include "Canvas.h"

CCanvas::CCanvas(sf::VideoMode videoMode, sf::String windowTitle)
{
    m_window.create(videoMode, windowTitle);
}

void CCanvas::AddShapes(std::vector<std::shared_ptr<CShape>> const& shapes)
{
    for (auto shape : shapes)
    {
        shape->Draw(*this);
    }
}

void CCanvas::DrawShapes()
{
    sf::RenderStates states;
    draw(m_window, states);
}

void CCanvas::DrawLine(CPoint const& startPoint, CPoint const& endPoint, sf::Color const& outlineColor)
{
    std::pair<sf::Vertex, sf::Vertex> line = 
    {
        sf::Vertex(sf::Vector2f(startPoint.x, startPoint.y), outlineColor),
        sf::Vertex(sf::Vector2f(endPoint.x, endPoint.y), outlineColor)
    };
    m_lines.push_back(line);
}

void CCanvas::FillPolygon(std::vector<CPoint> const vertices, sf::Color const& fillColor)
{
    sf::VertexArray polygon;
    polygon.resize(vertices.size());
    if (vertices.size() == 3)
    {
        polygon.setPrimitiveType(sf::Triangles);
    }
    else if (vertices.size() == 4)
    {
        polygon.setPrimitiveType(sf::Quads);
    }
    polygon[0].position = sf::Vector2f(vertices[0].x, vertices[0].y);
    polygon[1].position = sf::Vector2f(vertices[1].x, vertices[1].y);
    polygon[2].position = sf::Vector2f(vertices[2].x, vertices[2].y);

    polygon[0].color = fillColor;
    polygon[1].color = fillColor;
    polygon[2].color = fillColor;
    if (vertices.size() == 4)
    {
        polygon[3].position = sf::Vector2f(vertices[0].x, vertices[2].y);
        polygon[3].color = fillColor;
    }

    m_polygons.push_back(polygon);
}

void CCanvas::DrawCircle(CPoint const& center, float radius, sf::Color const& outlineColor)
{
    sf::CircleShape circle(radius);
    circle.setPosition(center.x, center.y);
    circle.setOutlineColor(outlineColor);
    circle.setOutlineThickness(3);
    m_circles.push_back(circle);
}
void CCanvas::FillCircle(CPoint const& center, float radius, sf::Color const& fillColor)
{
    m_circles[m_circles.size() - 1].setFillColor(fillColor);
}

void CCanvas::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto line : m_lines)
    {
        sf::Vertex lineArr[] =
        {
            line.first,
            line.second
        };
        target.draw(lineArr, 2, sf::Lines);
    }
    for (auto polygon : m_polygons)
    {
        target.draw(polygon);
    }
    for (auto circle : m_circles)
    {
        target.draw(circle);
    }
}

bool CCanvas::IsOpen() const
{
    return m_window.isOpen();
}

void CCanvas::Clear(sf::Color color)
{
    m_window.clear(color);
}

void CCanvas::Display()
{
    m_window.display();
}

bool CCanvas::PollEvent(sf::Event &event)
{
    return m_window.pollEvent(event);
}

void CCanvas::Close()
{
    return m_window.close();
}