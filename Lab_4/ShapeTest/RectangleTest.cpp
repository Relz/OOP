#include "stdafx.h"
#include "VerifyPoint.h"
#include "..\Shape\Rectangle.h"

struct RectangleFixture
{
    CRectangle rectangle;
    RectangleFixture()
        :rectangle({1, 1}, 50, 100, "000000", "0000FF")
    {}
};

BOOST_FIXTURE_TEST_SUITE(Rectangle_class, RectangleFixture)

    BOOST_AUTO_TEST_CASE(has_area)
    {
        BOOST_CHECK_CLOSE_FRACTION(rectangle.GetArea(), 50 * 100, 0.0001);
    }
    BOOST_AUTO_TEST_CASE(has_perimeter)
    {
        BOOST_CHECK_CLOSE_FRACTION(rectangle.GetPerimeter(), (50 + 100) * 2, 0.0001);
    }
    BOOST_AUTO_TEST_CASE(has_outline_color)
    {
        BOOST_CHECK_EQUAL(rectangle.GetOutlineColor(), "000000");
    }
    BOOST_AUTO_TEST_CASE(has_fill_color)
    {
        BOOST_CHECK_EQUAL(rectangle.GetFillColor(), "0000FF");
    }
    BOOST_AUTO_TEST_CASE(has_left_top)
    {
        VerifyPoint(rectangle.GetLeftTop(), 1, 1);
    }
    BOOST_AUTO_TEST_CASE(has_right_bottom)
    {
        VerifyPoint(rectangle.GetRightBottom(), 1 + 50, 1 + 100);
    }
    BOOST_AUTO_TEST_CASE(has_width)
    {
        BOOST_CHECK_EQUAL(rectangle.GetWidth(), 50);
    }
    BOOST_AUTO_TEST_CASE(has_height)
    {
        BOOST_CHECK_EQUAL(rectangle.GetHeight(), 100);
    }

BOOST_AUTO_TEST_SUITE_END()