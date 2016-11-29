#include "stdafx.h"
#include "Canvas.h"
#include "IShape.h"

void CCanvas::DrawShapes(std::vector<std::shared_ptr<IShape>> const& shapes)
{
    for (auto shape : shapes)
    {
        shape->Draw(*this);
    }
}

void CCanvas::DrawLine(CPoint const& startPoint, CPoint const& endPoint, Color const& outlineColor)
{

}

void CCanvas::FillPolygon(CPoint const vertices[3], Color const& fillColor)
{

}

void CCanvas::DrawCircle(CPoint const& center, double radius, Color const& outlineColor)
{

}
void CCanvas::FillCircle(CPoint const& center, double radius, Color const& fillColor)
{

}