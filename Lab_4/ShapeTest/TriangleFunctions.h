#pragma once
#include "stdafx.h"
#include "../Shape/Point.h"
#include "../Shape/Triangle.h"

float GetSideLength(CPoint const& vertex1, CPoint const& vertex2);
float GetPerimeter(CTriangle &triangle);
float GetPerimeter(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3);
float GetArea(CTriangle &triangle);
float GetArea(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3);