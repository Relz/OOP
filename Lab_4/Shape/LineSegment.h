#pragma once
#include "Shape.h"
#include "Point.h"

class CLineSegment : public CShape
{
public:
    CLineSegment(CPoint const& startPoint, CPoint const& endPoint, std::string const& outlineColor);
    ~CLineSegment() = default;
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;

    CPoint const& GetStartPoint() const;
    CPoint const& GetEndPoint() const;
private:
    std::string m_outlineColor;
    CPoint m_startPoint;
    CPoint m_endPoint;
};

