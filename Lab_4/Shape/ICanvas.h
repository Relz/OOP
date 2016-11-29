#pragma once
#include "Point.h"
#include "color.h"

class ICanvas
{
public:
    virtual ~ICanvas() = default;

    virtual void DrawLine(CPoint const& startPoint, CPoint const& endPoint, Color const& outlineColor) = 0;
    virtual void FillPolygon(CPoint const vertices[3], Color const& fillColor) = 0;
    virtual void DrawCircle(CPoint const& center, float radius, Color const& outlineColor) = 0;
    virtual void FillCircle(CPoint const& center, float radius, Color const& fillColor) = 0;
};