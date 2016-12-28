#include "stdafx.h"
#include "Shape.h"

CShape::CShape(std::string const& shapeType, std::string const& outlineColor)
    : m_shapeType(shapeType)
    , m_outlineColor(outlineColor)
{
 
}

std::string CShape::GetOutlineColor() const
{
    return m_outlineColor;
}

std::string CShape::ToString() const
{
    std::ostringstream strm;
    strm << m_shapeType + ":\n"
        << "  Area = " << GetArea() << "\n"
        << "  Outline color = " << GetOutlineColor() << "\n";
    AppendProperties(strm);
    return strm.str();
}