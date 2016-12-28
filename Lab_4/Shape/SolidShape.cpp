#include "stdafx.h"
#include "SolidShape.h"

CSolidShape::CSolidShape(std::string const& shapeType, std::string const& outlineColor, std::string const& fillColor)
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
    strm << "  Fill color = " << GetFillColor() << "\n";
    AppendPropertiesSolid(strm);
}