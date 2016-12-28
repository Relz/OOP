#pragma once
#include "ISolidShape.h"

class CSolidShape: public ISolidShape, public CShape
{
public:
    CSolidShape(std::string const& shapeType, std::string const& outlineColor, std::string const& fillColor);
    ~CSolidShape() = default;
    std::string GetFillColor() const override final;
protected:
    virtual void AppendPropertiesSolid(std::ostream & strm) const = 0;
private:
    void AppendProperties(std::ostream & strm) const;
    std::string m_fillColor;

};

