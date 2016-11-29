#pragma once
#include "ICanvas.h"
#include "Point.h"
#include "Shape.h"
#include "color.h"

class CCanvas : public ICanvas, public sf::Drawable, public sf::Window
{
public:
    CCanvas(sf::VideoMode videoMode, sf::String windowTitle);
    ~CCanvas() = default;

    void AddShapes(std::vector<std::shared_ptr<CShape>> const& shapes);
    void DrawShapes();
    void DrawLine(CPoint const& startPoint, CPoint const& endPoint, Color const& outlineColor) override;
    void FillPolygon(CPoint const vertices[3], Color const& fillColor) override;
    void DrawCircle(CPoint const& center, float radius, Color const& outlineColor) override;
    void FillCircle(CPoint const& center, float radius, Color const& fillColor) override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool IsOpen() const;
    void Clear(sf::Color);
    void Display();
    bool PollEvent(sf::Event &event);
    void Close();
private:
    sf::RenderWindow m_window;
    std::vector<std::pair<sf::Vertex, sf::Vertex>> m_lines;
};