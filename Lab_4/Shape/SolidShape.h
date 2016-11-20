#pragma once
#include "Shape.h"

class ISolidShape :
    public IShape
{
public:
    ISolidShape() = default;
    virtual ~ISolidShape() = default;
    virtual std::string GetFillColor() const = 0;
};

