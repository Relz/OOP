#pragma once
#include "IShape.h"

class CShape : IShape
{
public:
    CShape(std::string outlineColor);
    ~CShape() = default;
    virtual double GetArea() const = 0;
    virtual double GetPerimeter() const = 0;
    virtual std::string ToString() const = 0;
    std::string GetOutlineColor() const override final;
protected:
    std::string m_outlineColor;
};

