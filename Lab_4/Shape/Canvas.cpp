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

void CCanvas::DrawLine(CPoint const& startPoint, CPoint const& endPoint, Color const& outlineColor)
{
    sf::Color color(outlineColor.r, outlineColor.g, outlineColor.b);
    std::pair<sf::Vertex, sf::Vertex> line = 
    {
        sf::Vertex(sf::Vector2f(startPoint.x, startPoint.y), color),
        sf::Vertex(sf::Vector2f(endPoint.x, endPoint.y), color)
    };
    m_lines.push_back(line);
}

void CCanvas::FillPolygon(CPoint const vertices[3], Color const& fillColor)
{
    sf::VertexArray triangle(sf::Quads, 4);
    triangle[0].position = sf::Vector2f(vertices[0].x, vertices[0].y);
    triangle[1].position = sf::Vector2f(vertices[1].x, vertices[1].y);
    triangle[2].position = sf::Vector2f(vertices[2].x, vertices[2].y);
    triangle[3].position = sf::Vector2f(vertices[0].x, vertices[2].y);

    sf::Color color(fillColor.r, fillColor.g, fillColor.b);
    triangle[0].color = color;
    triangle[1].color = color;
    triangle[2].color = color;
    triangle[3].color = color;
    m_fills.push_back(triangle);
}

void CCanvas::DrawCircle(CPoint const& center, float radius, Color const& outlineColor)
{

}
void CCanvas::FillCircle(CPoint const& center, float radius, Color const& fillColor)
{

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
    for (auto triangle : m_fills)
    {
        target.draw(triangle);
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