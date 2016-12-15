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
    BOOST_AUTO_TEST_CASE(to_string)
    {
        std::stringstream expectedStr;
        expectedStr << "Circle:" << "\n"
            << "  Area = " << (boost::math::constants::pi<float>() * 5.f * 5.f) << "\n"
            << "  Outline color = 000000" << "\n"
            << "  Fill color = 0000FF" << "\n"
            << "  Circumference = " << (boost::math::constants::two_pi<float>() * 5.f) << "\n"
            << "  Center point = (5.000000, 10.000000)" << "\n"
            << "  Radius = 5" << "\n";
        BOOST_CHECK_EQUAL(circle.ToString(), expectedStr.str());
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Circle_class)

    BOOST_AUTO_TEST_CASE(can_be_initialized_from_ifstream)
    {
        std::shared_ptr<CCircle> circle;
        std::stringstream input("0 0 10 010101 FAFAFA");
        BOOST_CHECK(input >> circle);
        VerifyPoint(circle->GetCenter(), 0.f, 0.f);
        BOOST_CHECK_EQUAL(circle->GetRadius(), 10);
        BOOST_CHECK_EQUAL(circle->GetArea(), boost::math::constants::pi<float>() * 10 * 10);
        BOOST_CHECK_EQUAL(circle->GetPerimeter(), boost::math::constants::two_pi<float>() * 10);
        BOOST_CHECK_EQUAL(circle->GetOutlineColor(), "010101");
        BOOST_CHECK_EQUAL(circle->GetFillColor(), "FAFAFA");
    }
    BOOST_AUTO_TEST_CASE(cant_be_initialized_from_wrong_ifstream)
    {
        std::shared_ptr<CCircle> circle;
        std::stringstream input("0 0 0 4 5 0");
        BOOST_CHECK(!(input >> circle));
    }

BOOST_AUTO_TEST_SUITE_END()