#pragma once
#include "Point.h"
#include "Shape.h"

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

    void SetStartPoint(CPoint const& startPoint);
    void SetEndPoint(CPoint const& endPoint);
    void SetOutlineColor(std::string const& outlineColor);
private:
    std::string m_outlineColor;
    CPoint m_startPoint;
    CPoint m_endPoint;
};

bool operator >> (std::istream & in, std::shared_ptr<CLineSegment> & line);