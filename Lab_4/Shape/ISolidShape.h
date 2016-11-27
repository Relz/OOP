#pragma once
#include "IShape.h"

class ISolidShape : public IShape
{
public:
    ISolidShape() = default;
    ~ISolidShape() = default;
    virtual std::string GetFillColor() const = 0;
};

