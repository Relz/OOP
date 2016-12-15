#include "stdafx.h"
#include "VerifyPoint.h"
#include "..\Shape\LineSegment.h"

struct LineSegmentFixture
{
    CLineSegment line;
    LineSegmentFixture()
        :line({ 5, 10 }, { 9, 7 }, "000000")
    {}
};

BOOST_FIXTURE_TEST_SUITE(LineSegment_class, LineSegmentFixture)

    BOOST_AUTO_TEST_CASE(has_zero_area)
    {
        BOOST_CHECK_EQUAL(line.GetArea(), 0);
    }
    BOOST_AUTO_TEST_CASE(has_perimeter)
    {
        BOOST_CHECK_EQUAL(line.GetPerimeter(), 5);
    }
    BOOST_AUTO_TEST_CASE(has_outline_color)
    {
        BOOST_CHECK_EQUAL(line.GetOutlineColor(), "000000");
    }
    BOOST_AUTO_TEST_CASE(has_start_point)
    {
        VerifyPoint(line.GetStartPoint(), 5, 10);
    }
    BOOST_AUTO_TEST_CASE(has_end_point)
    {
        VerifyPoint(line.GetEndPoint(), 9, 7);
    }
    BOOST_AUTO_TEST_CASE(to_string)
    {
        std::stringstream expectedStr;
        expectedStr << "Line:" << "\n"
            << "  Area = 0" << "\n"
            << "  Outline color = 000000" << "\n"
            << "  Perimeter = 5" << "\n"
            << "  Start point = (5.000000, 10.000000)" << "\n"
            << "  End point = (9.000000, 7.000000)" << "\n";
        BOOST_CHECK_EQUAL(line.ToString(), expectedStr.str());
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(LineSegment_class)

    BOOST_AUTO_TEST_CASE(can_be_initialized_from_ifstream)
    {
        std::shared_ptr<CLineSegment> line;
        std::stringstream input("0 0 0 5 010101 FAFAFA");
        BOOST_CHECK(input >> line);
        VerifyPoint(line->GetStartPoint(), 0.f, 0.f);
        VerifyPoint(line->GetEndPoint(), 0.f, 5.f);
        BOOST_CHECK_EQUAL(line->GetArea(), 0);
        BOOST_CHECK_EQUAL(line->GetPerimeter(), 5);
        BOOST_CHECK_EQUAL(line->GetOutlineColor(), "010101");
    }
    BOOST_AUTO_TEST_CASE(cant_be_initialized_from_wrong_ifstream)
    {
        std::shared_ptr<CLineSegment> line;
        std::stringstream input("0 0 0 4 5 0");
        BOOST_CHECK(!(input >> line));
    }

BOOST_AUTO_TEST_SUITE_END()