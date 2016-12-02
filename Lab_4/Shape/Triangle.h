#pragma once
#include "Point.h"
#include "SolidShape.h"

class CTriangle : public CSolidShape
{
public:
    CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, 
              std::string const& outlineColor, std::string const& fillColor);
    ~CTriangle() = default;
    float GetSideLength(CPoint const& vertex1, CPoint const& vertex2) const;
    float GetArea() const override;
    float GetPerimeter() const override;

    CPoint const& GetVertex1() const;
    CPoint const& GetVertex2() const;
    CPoint const& GetVertex3() const;

    void Draw(ICanvas & canvas) const override;
protected:
    void AppendPropertiesSolid(std::ostream & strm) const;
private:
    std::vector<CPoint> m_vertices;
};

bool operator >> (std::istream & in, std::shared_ptr<CTriangle> & triangle);