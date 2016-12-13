#include "stdafx.h"
#include "VerifyPoint.h"
#include "..\Shape\Triangle.h"

float GetSideLength(CPoint const& vertex1, CPoint const& vertex2)
{
    return std::hypot(vertex2.x - vertex1.x, vertex2.y - vertex1.y);
}

float GetPerimeter(CTriangle &triangle)
{
    return GetSideLength(triangle.GetVertex1(), triangle.GetVertex2()) +
        GetSideLength(triangle.GetVertex2(), triangle.GetVertex3()) +
        GetSideLength(triangle.GetVertex3(), triangle.GetVertex1());
}

float GetArea(CTriangle &triangle)
{
    float semiperimeter = GetPerimeter(triangle) / 2;
    return std::sqrt(semiperimeter *
        (semiperimeter - GetSideLength(triangle.GetVertex1(), triangle.GetVertex2())) *
        (semiperimeter - GetSideLength(triangle.GetVertex2(), triangle.GetVertex3())) *
        (semiperimeter - GetSideLength(triangle.GetVertex3(), triangle.GetVertex1()))
    );
}

struct TriangleFixture
{
    CTriangle triangle;
    TriangleFixture()
        :triangle({ 5, 10 }, { 9, 7 }, { 6, 8 }, "000000", "0000FF")
    {}
};

BOOST_FIXTURE_TEST_SUITE(Triangle_class, TriangleFixture)

    BOOST_AUTO_TEST_CASE(has_vertex1)
    {
        VerifyPoint(triangle.GetVertex1(), 5, 10);
    }
    BOOST_AUTO_TEST_CASE(has_vertex2)
    {
        VerifyPoint(triangle.GetVertex2(), 9, 7);
    }
    BOOST_AUTO_TEST_CASE(has_vertex3)
    {
        VerifyPoint(triangle.GetVertex3(), 6, 8);
    }
    BOOST_AUTO_TEST_CASE(has_side_length)
    {
        BOOST_CHECK_EQUAL(triangle.GetSideLength(triangle.GetVertex1(), triangle.GetVertex2()), 5);
    }
    BOOST_AUTO_TEST_CASE(has_perimeter)
    {
        BOOST_CHECK_CLOSE_FRACTION(triangle.GetPerimeter(), GetPerimeter(triangle), FLT_EPSILON);
    }
    BOOST_AUTO_TEST_CASE(has_area)
    {
        BOOST_CHECK_CLOSE_FRACTION(triangle.GetArea(), GetArea(triangle), FLT_EPSILON);
    }
    BOOST_AUTO_TEST_CASE(has_outline_color)
    {
        BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), "000000");
    }
    BOOST_AUTO_TEST_CASE(has_fill_color)
    {
        BOOST_CHECK_EQUAL(triangle.GetFillColor(), "0000FF");
    }
    BOOST_AUTO_TEST_CASE(to_string)
    {
        BOOST_CHECK_EQUAL(triangle.ToString(), "Triangle:\n  Area = 2.5\n  Outline color = 000000\n  Fill color = 0000FF\n  Perimeter = 10.3983\n  Vertex 1 = (5.000000, 10.000000)\n  Vertex 2 = (5.000000, 10.000000)\n  Vertex 3 = (5.000000, 10.000000)\n  Side length 1 = 5\n  Side length 2 = 3.16228\n  Side length 3 = 2.23607\n");
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Triangle_class)

    BOOST_AUTO_TEST_CASE(vertices_cant_be_in_one_point)
    {
        BOOST_REQUIRE_THROW(CTriangle({ 0, 0 }, { 0, 0 }, { 0, 0 }, "000000", "000000"), std::invalid_argument);
        BOOST_REQUIRE_THROW(CTriangle({ 0, 0 }, { 0, 0 }, { 0, 1 }, "000000", "000000"), std::invalid_argument);
        BOOST_REQUIRE_THROW(CTriangle({ 0, 0 }, { 0, 1 }, { 0, 0 }, "000000", "000000"), std::invalid_argument);
        BOOST_REQUIRE_THROW(CTriangle({ 0, 1 }, { 0, 0 }, { 0, 0 }, "000000", "000000"), std::invalid_argument);
    }
    BOOST_AUTO_TEST_CASE(can_be_initialized_from_ifstream)
    {
        std::shared_ptr<CTriangle> triangle;
        std::stringstream input("0 0 0 4 5 0 010101 FAFAFA");
        BOOST_CHECK(input >> triangle);
        VerifyPoint(triangle->GetVertex1(), 0.f, 0.f);
        VerifyPoint(triangle->GetVertex2(), 0.f, 4.f);
        VerifyPoint(triangle->GetVertex3(), 5.f, 0.f);
        BOOST_CHECK_EQUAL(triangle->GetOutlineColor(), "010101");
        BOOST_CHECK_EQUAL(triangle->GetFillColor(), "FAFAFA");
    }
    BOOST_AUTO_TEST_CASE(cant_be_initialized_from_wrong_ifstream)
    {
        std::shared_ptr<CTriangle> triangle;
        std::stringstream input("0 0 0 4 5 0");
        BOOST_CHECK(!(input >> triangle));
    }

BOOST_AUTO_TEST_SUITE_END()