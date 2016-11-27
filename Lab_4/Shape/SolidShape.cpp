#include "stdafx.h"
#include "SolidShape.h"

CSolidShape::CSolidShape(std::string fillColor)
    : m_fillColor(fillColor)
{

}

std::string CSolidShape::GetFillColor() const
{
    return m_fillColor;
}