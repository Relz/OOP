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
    std::pair<sf::Vertex, sf::Vertex> line = 
    {
        sf::Vertex(sf::Vector2f(startPoint.x, startPoint.y)),
        sf::Vertex(sf::Vector2f(endPoint.x, endPoint.y))
    };
    m_lines.push_back(line);
}

void CCanvas::FillPolygon(CPoint const vertices[3], Color const& fillColor)
{

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