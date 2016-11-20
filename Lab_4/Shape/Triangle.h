#pragma once
#include "Point.h"
#include "SolidShape.h"

class CTriangle :
    public ISolidShape
{
public:
    CTriangle(CPoint const& firstVertex, CPoint const& secondVertex, CPoint const& thirdVertex, 
              std::string const& outlineColor, std::string const& fillColor);
    virtual ~CTriangle() = default;
    double CTriangle::GetSideLength(CPoint const& firstVertex, CPoint const& secondVertex) const;
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    std::string GetOutlineColor() const override;
    std::string GetFillColor() const override;

    CPoint const& GetVertex1() const;
    CPoint const& GetVertex2() const;
    CPoint const& GetVertex3() const;
private:
    CPoint m_vertices[3] = {};
    std::string m_outlineColor;
    std::string m_fillColor;
};

