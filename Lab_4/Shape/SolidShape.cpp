#include "stdafx.h"
#include "SolidShape.h"

CSolidShape::CSolidShape(std::string shapeType, std::string outlineColor, std::string fillColor)
    : ISolidShape(shapeType, outlineColor)
    , m_fillColor(fillColor)
{

}

std::string CSolidShape::GetFillColor() const
{
    return m_fillColor;
}

void CSolidShape::AppendProperties(std::ostream & strm) const
{
    strm << "  Fill color = " << GetFillColor();
}