#pragma once
#include "Point.h"
#include "SolidShape.h"

class CCircle : public CSolidShape
{
public:
    CCircle(CPoint const& center, double radius, std::string const& outlineColor, std::string const& fillColor);
    ~CCircle() = default;
    double GetArea() const;
    double GetPerimeter() const;
    CPoint const& GetCenter() const;
    double GetRadius() const;

    void Draw(ICanvas & canvas) const override;
protected:
    void AppendProperties(std::ostream & strm) const override;
private:
    CPoint m_center;
    double m_radius = 0;
};

bool operator >> (std::istream & in, std::shared_ptr<CCircle> & circle);