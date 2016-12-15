#include "TriangleFunctions.h"

float GetSideLength(CPoint const& vertex1, CPoint const& vertex2)
{
    return std::hypot(vertex2.x - vertex1.x, vertex2.y - vertex1.y);
}

float GetPerimeter(CTriangle &triangle)
{
    return GetSideLength(triangle.GetVertex1(), triangle.GetVertex2()) +
        GetSideLength(triangle.GetVertex2(), triangle.GetVertex3()) +
        GetSideLength(triangle.GetVertex3(), triangle.GetVertex1());
}

float GetPerimeter(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3)
{
    return GetSideLength(vertex1, vertex2) + GetSideLength(vertex2, vertex3) + GetSideLength(vertex3, vertex1);
}

float GetArea(CTriangle &triangle)
{
    float semiperimeter = GetPerimeter(triangle) / 2;
    return std::sqrt(semiperimeter *
        (semiperimeter - GetSideLength(triangle.GetVertex1(), triangle.GetVertex2())) *
        (semiperimeter - GetSideLength(triangle.GetVertex2(), triangle.GetVertex3())) *
        (semiperimeter - GetSideLength(triangle.GetVertex3(), triangle.GetVertex1()))
    );
}

float GetArea(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3)
{
    float semiperimeter = GetPerimeter(vertex1, vertex2, vertex3) / 2;
    return std::sqrt(semiperimeter *
        (semiperimeter - GetSideLength(vertex1, vertex2)) *
        (semiperimeter - GetSideLength(vertex2, vertex3)) *
        (semiperimeter - GetSideLength(vertex3, vertex1))
    );
}