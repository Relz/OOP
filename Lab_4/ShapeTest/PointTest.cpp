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
    BOOST_AUTO_TEST_CASE(can_get_string_value)
    {
        CPoint point(10.f, 20.f);
        BOOST_CHECK_EQUAL(point.ToString(), "(10.000000, 20.000000)");
    }
    BOOST_AUTO_TEST_CASE(can_be_initialized_from_ifstream)
    {
        CPoint point;
        std::stringstream input("10 20");
        input >> point;
        VerifyPoint(point, 10.f, 20.f);
    }
    BOOST_AUTO_TEST_CASE(cant_be_initialized_from_wrong_ifstream)
    {
        CPoint point;
        std::stringstream input("");
        BOOST_CHECK(!(input >> point));
    }

BOOST_AUTO_TEST_SUITE_END()