#pragma once
#include "Shape.h"

class CSolidShape: public CShape
{
public:
    CSolidShape(std::string const& shapeType, std::string const& outlineColor, std::string const& fillColor);
    std::string GetFillColor() const;
protected:
    virtual void AppendPropertiesSolid(std::ostream & strm) const = 0;
private:
    void AppendProperties(std::ostream & strm) const;
    std::string m_fillColor;

};

