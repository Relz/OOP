#pragma once
#include "Point.h"
#include "SolidShape.h"

class CCircle : public CSolidShape
{
public:
    CCircle(CPoint const& center, float radius, std::string const& outlineColor, std::string const& fillColor);
    float GetArea() const override;
    float GetPerimeter() const override;
    CPoint const& GetCenter() const;
    float GetRadius() const;

    void Draw(ICanvas & canvas) const override;
protected:
    void AppendPropertiesSolid(std::ostream & strm) const;
private:
    CPoint m_center;
    float m_radius = 0;
};

bool operator >> (std::istream & in, std::shared_ptr<CCircle> & circle);