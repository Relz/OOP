#pragma once
#include "IShape.h"

class CShape : IShape
{
public:
    CShape(std::string outlineColor);
    ~CShape() = default;
    std::string GetOutlineColor() const override final;
private:
    std::string m_outlineColor;
};

