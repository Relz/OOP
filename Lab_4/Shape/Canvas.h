#pragma once
#include "ICanvas.h"
#include "Point.h"
#include "IShape.h"
#include "color.h"

class CCanvas : public ICanvas
{
public:
    CCanvas() = default;
    ~CCanvas() = default;
        
    void DrawShapes(std::vector<std::shared_ptr<IShape>> const& shapes);
    void DrawLine(CPoint const& startPoint, CPoint const& endPoint, Color const& outlineColor) override;
    void FillPolygon(CPoint const vertices[3], Color const& fillColor) override;
    void DrawCircle(CPoint const& center, double radius, Color const& outlineColor) override;
    void FillCircle(CPoint const& center, double radius, Color const& fillColor) override;
};