#pragma once
#include "ISolidShape.h"

class CSolidShape: public ISolidShape
{
public:
    CSolidShape(std::string shapeType, std::string outlineColor, std::string fillColor);
    ~CSolidShape() = default;
    std::string GetFillColor() const final;
protected:
    void AppendProperties(std::ostream & strm) const override;
private:
    std::string m_fillColor;
};

