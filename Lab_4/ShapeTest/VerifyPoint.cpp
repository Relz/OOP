#include "VerifyPoint.h"

void VerifyPoint(CPoint const& point, float expectedX, float expectedY)
{
    BOOST_CHECK_CLOSE_FRACTION(point.x, expectedX, FLT_EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(point.y, expectedY, FLT_EPSILON);
}