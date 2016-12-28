#pragma once
#include "IShape.h"

class CShape : public IShape
{
public:
    CShape(std::string const& shapeType, std::string const& outlineColor);
    virtual float GetArea() const = 0;
    virtual float GetPerimeter() const = 0;
    std::string ToString() const override final;
    std::string GetOutlineColor() const override final;
protected:
    virtual void AppendProperties(std::ostream &strm) const = 0;
private:
    std::string m_shapeType;
    std::string m_outlineColor;
};

