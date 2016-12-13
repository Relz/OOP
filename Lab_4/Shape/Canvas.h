#pragma once
#include "ICanvas.h"
#include "Point.h"
#include "Shape.h"
#include "color.h"

class CCanvas : public ICanvas, public sf::Drawable
{
public:
    CCanvas(sf::VideoMode videoMode, sf::String windowTitle);
    ~CCanvas() = default;

    void AddShapes(std::vector<std::shared_ptr<CShape>> const& shapes);
    void DrawShapes();
    void DrawLine(CPoint const& startPoint, CPoint const& endPoint, sf::Color const& outlineColor) override;
    void FillPolygon(std::vector<CPoint> const vertices, sf::Color const& fillColor) override;
    void DrawCircle(CPoint const& center, float radius, sf::Color const& outlineColor) override;
    void FillCircle(CPoint const& center, float radius, sf::Color const& fillColor) override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool IsOpen() const;
    void Clear(sf::Color);
    void Display();
    bool PollEvent(sf::Event &event);
    void Close();
private:
    void DrawInnerCircle(CPoint const& center, float radius);

    sf::RenderWindow m_window;
    std::vector<sf::VertexArray> m_shapes;
};