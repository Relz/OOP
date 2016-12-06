#include "stdafx.h"
#include "VerifyPoint.h"
#include "..\Shape\Point.h"

BOOST_AUTO_TEST_SUITE(Point_class)

    BOOST_AUTO_TEST_CASE(can_explicit_init_point)
    {
        CPoint point = { 10.f, 25.8f };
        VerifyPoint(point, 10.f, 25.8f);
    }
    BOOST_AUTO_TEST_CASE(can_init_point_via_constructor)
    {
        CPoint point(10.f, 25.8f);
        VerifyPoint(point, 10.f, 25.8f);
    }
    BOOST_AUTO_TEST_CASE(can_init_point_via_fields)
    {
        CPoint point;
        point.x = 10.f;
        point.y = 25.8f;
        VerifyPoint(point, 10.f, 25.8f);
    }

BOOST_AUTO_TEST_SUITE_END()