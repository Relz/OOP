#pragma once
#include "Point.h"
#include "SolidShape.h"

class CRectangle : public CSolidShape
{
public:
    CRectangle(CPoint const& leftTop, float width, float height, std::string const& outlineColor, std::string const& fillColor);
    float GetArea() const override;
    float GetPerimeter() const override;
    CPoint const& GetLeftTop() const;
    CPoint const GetRightBottom() const;
    float GetWidth() const;
    float GetHeight() const;

    void Draw(ICanvas & canvas) const override;
protected:
    void AppendPropertiesSolid(std::ostream & strm) const;
private:
    CPoint m_leftTop;
    float m_width;
    float m_height;
};

bool operator >> (std::istream & in, std::shared_ptr<CRectangle> & rectangle);