#pragma once
#include "Point.h"
#include "SolidShape.h"

class CRectangle : public CSolidShape
{
public:
    CRectangle(CPoint const& leftTop, double width, double height, std::string const& outlineColor, std::string const& fillColor);
    ~CRectangle() = default;
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    CPoint const& GetLeftTop() const;
    CPoint const GetRightBottom() const;
    double GetWidth() const;
    double GetHeight() const;
private:
    CPoint m_leftTop;
    double m_width;
    double m_height;
};

bool operator >> (std::istream & in, std::shared_ptr<CRectangle> & rectangle);