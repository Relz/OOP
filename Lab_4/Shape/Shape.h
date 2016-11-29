#pragma once
#include "IShape.h"

class CShape : IShape
{
public:
    CShape(std::string shapeType, std::string outlineColor);
    ~CShape() = default;
    virtual double GetArea() const = 0;
    virtual double GetPerimeter() const = 0;
    std::string ToString() const final;
    std::string GetOutlineColor() const final;
protected:
    virtual void AppendProperties(std::ostream &strm) const = 0;
private:
    std::string m_shapeType;
    std::string m_outlineColor;
};

