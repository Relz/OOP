#include "stdafx.h"
#include "VerifyPoint.h"
#include "..\Shape\LineSegment.h"

struct LineSegmentFixture
{
    CLineSegment line;
    LineSegmentFixture()
        :line({ 5, 10 }, { 9, 7 }, "#000000")
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
        BOOST_CHECK_EQUAL(line.GetOutlineColor(), "#000000");
    }
    BOOST_AUTO_TEST_CASE(has_start_point)
    {
        VerifyPoint(line.GetStartPoint(), 5, 10);
    }
    BOOST_AUTO_TEST_CASE(has_end_point)
    {
        VerifyPoint(line.GetEndPoint(), 9, 7);
    }

BOOST_AUTO_TEST_SUITE_END()