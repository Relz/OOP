#pragma once
#include "ISolidShape.h"

class CSolidShape: public ISolidShape
{
public:
    CSolidShape(std::string shapeType, std::string outlineColor, std::string fillColor);
    ~CSolidShape() = default;
    std::string GetFillColor() const final;
protected:
    virtual void AppendPropertiesSolid(std::ostream & strm) const = 0;
private:
    void AppendProperties(std::ostream & strm) const;
    std::string m_fillColor;

};

