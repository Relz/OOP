#pragma once
#include "Shape.h"

class ISolidShape : public CShape
{
public:
    ISolidShape(std::string shapeType, std::string outlineColor);
    ~ISolidShape() = default;
    virtual std::string GetFillColor() const = 0;
};

