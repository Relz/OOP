#pragma once
#include "Point.h"
#include "Shape.h"

class CLineSegment : public CShape
{
public:
    CLineSegment(CPoint const& startPoint, CPoint const& endPoint, std::string const& outlineColor);
    ~CLineSegment() = default;
    float GetArea() const override;
    float GetPerimeter() const override;
    CPoint const& GetStartPoint() const;
    CPoint const& GetEndPoint() const;

    void Draw(ICanvas & canvas) const override;
protected:
    void AppendProperties(std::ostream & strm) const override;
private:
    CPoint m_startPoint;
    CPoint m_endPoint;
};

bool operator >> (std::istream & in, std::shared_ptr<CLineSegment> & line);