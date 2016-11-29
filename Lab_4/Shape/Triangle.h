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

    CPoint const& GetVertex1() const;
    CPoint const& GetVertex2() const;
    CPoint const& GetVertex3() const;

    void Draw(ICanvas & canvas) const override;
protected:
    void AppendProperties(std::ostream & strm) const override;
private:
    CPoint m_vertices[3] = {};
};

bool operator >> (std::istream & in, std::shared_ptr<CTriangle> & triangle);