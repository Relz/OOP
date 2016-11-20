#include "VerifyPoint.h"

void VerifyPoint(CPoint const& point, double expectedX, double expectedY)
{
    BOOST_CHECK_CLOSE_FRACTION(point.x, expectedX, 0.0001);
    BOOST_CHECK_CLOSE_FRACTION(point.y, expectedY, 0.0001);
}