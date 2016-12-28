#pragma once
#include "Point.h"
#include "Color.h"

class ICanvas
{
public:
    virtual void DrawLine(CPoint const& startPoint, CPoint const& endPoint, sf::Color const& outlineColor) = 0;
    virtual void FillPolygon(std::vector<CPoint> const vertices, sf::Color const& fillColor) = 0;
    virtual void DrawCircle(CPoint const& center, float radius, sf::Color const& outlineColor) = 0;
    virtual void FillCircle(CPoint const& center, float radius, sf::Color const& fillColor) = 0;
};