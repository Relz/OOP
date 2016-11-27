#pragma once
#include "Point.h"
#include "SolidShape.h"

class CTriangle : public CSolidShape
{
public:
    CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, 
              std::string const& outlineColor, std::string const& fillColor);
    ~CTriangle() = default;
    double CTriangle::GetSideLength(CPoint const& vertex1, CPoint const& vertex2) const;
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    std::string GetOutlineColor() const override;

    CPoint const& GetVertex1() const;
    CPoint const& GetVertex2() const;
    CPoint const& GetVertex3() const;
private:
    CPoint m_vertices[3] = {};
    std::string m_outlineColor;
    std::string m_fillColor;
};

