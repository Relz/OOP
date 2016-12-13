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
        BOOST_CHECK_CLOSE_FRACTION(rectangle.GetArea(), 50.f * 100.f, FLT_EPSILON);
    }
    BOOST_AUTO_TEST_CASE(has_perimeter)
    {
        BOOST_CHECK_CLOSE_FRACTION(rectangle.GetPerimeter(), (50 + 100) * 2.f, FLT_EPSILON);
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
    BOOST_AUTO_TEST_CASE(to_string)
    {
        BOOST_CHECK_EQUAL(rectangle.ToString(), "Rectangle:\n  Area = 5000\n  Outline color = 000000\n  Fill color = 0000FF\n  Perimeter = 300\n  Left-Top point = (1.000000, 1.000000)\n  Right-Bottom point = (51.000000, 101.000000)\n  Width = 50\n  Height = 100\n");
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Rectangle_class)

    BOOST_AUTO_TEST_CASE(can_be_initialized_from_ifstream)
    {
        std::shared_ptr<CRectangle> rectangle;
        std::stringstream input("1 1 50 100 010101 FAFAFA");
        BOOST_CHECK(input >> rectangle);
        BOOST_CHECK_EQUAL(rectangle->GetWidth(), 50);
        BOOST_CHECK_EQUAL(rectangle->GetHeight(), 100);
        VerifyPoint(rectangle->GetLeftTop(), 1.f, 1.f);
        VerifyPoint(rectangle->GetRightBottom(), 51.f, 101.f);
        BOOST_CHECK_EQUAL(rectangle->GetArea(), 5000);
        BOOST_CHECK_EQUAL(rectangle->GetPerimeter(), 300);
        BOOST_CHECK_EQUAL(rectangle->GetOutlineColor(), "010101");
        BOOST_CHECK_EQUAL(rectangle->GetFillColor(), "FAFAFA");
    }
    BOOST_AUTO_TEST_CASE(cant_be_initialized_from_wrong_ifstream)
    {
        std::shared_ptr<CRectangle> rectangle;
        std::stringstream input("0 0 0 4 5 0");
        BOOST_CHECK(!(input >> rectangle));
    }

BOOST_AUTO_TEST_SUITE_END()