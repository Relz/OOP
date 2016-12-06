#include "stdafx.h"
#include "VerifyPoint.h"
#include "..\Shape\Circle.h"

struct CircleFixture
{
    CCircle circle;
    CircleFixture()
        :circle({5, 10}, 5, "000000", "0000FF")
    {}
};

BOOST_FIXTURE_TEST_SUITE(Circle_class, CircleFixture)

    BOOST_AUTO_TEST_CASE(has_area)
    {
        BOOST_CHECK_CLOSE_FRACTION(circle.GetArea(), boost::math::constants::pi<float>() * 5.f * 5.f, FLT_EPSILON);
    }
    BOOST_AUTO_TEST_CASE(has_perimeter)
    {
        BOOST_CHECK_CLOSE_FRACTION(circle.GetPerimeter(), boost::math::constants::two_pi<float>() * 5.f, FLT_EPSILON);
    }
    BOOST_AUTO_TEST_CASE(has_outline_color)
    {
        BOOST_CHECK_EQUAL(circle.GetOutlineColor(), "000000");
    }
    BOOST_AUTO_TEST_CASE(has_fill_color)
    {
        BOOST_CHECK_EQUAL(circle.GetFillColor(), "0000FF");
    }
    BOOST_AUTO_TEST_CASE(has_center)
    {
        VerifyPoint(circle.GetCenter(), 5, 10);
    }
    BOOST_AUTO_TEST_CASE(has_radius)
    {
        BOOST_CHECK_EQUAL(circle.GetRadius(), 5);
    }

BOOST_AUTO_TEST_SUITE_END()