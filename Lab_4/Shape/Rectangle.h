#pragma once
#include "Point.h"
#include "SolidShape.h"

class CRectangle : public ISolidShape
{
public:
    CRectangle(CPoint const& leftTop, double width, double height, std::string const& outlineColor, std::string const& fillColor);
    ~CRectangle() = default;
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    std::string GetOutlineColor() const override;
    std::string GetFillColor() const override;
    CPoint const& GetLeftTop() const;
    CPoint const GetRightBottom() const;
    double GetWidth() const;
    double GetHeight() const;
private:
    CPoint m_leftTop;
    double m_width;
    double m_height;
    std::string m_outlineColor;
    std::string m_fillColor;
};

