#include "stdafx.h"
#include "SolidShape.h"

CSolidShape::CSolidShape(std::string outlineColor, std::string fillColor)
    : ISolidShape(outlineColor)
    , m_fillColor(fillColor)
{

}

std::string CSolidShape::GetFillColor() const
{
    return m_fillColor;
}