#pragma once
#include "ISolidShape.h"

class CSolidShape: public ISolidShape
{
public:
    CSolidShape(std::string outlineColor, std::string fillColor);
    ~CSolidShape() = default;
    std::string GetFillColor() const override final;
protected:
    std::string m_fillColor;
};

