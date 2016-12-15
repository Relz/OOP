#include "stdafx.h"
#include "VerifyPoint.h"
#include "..\Shape\ShapeController.h"
#include "TriangleFunctions.h"

struct ShapeControllerFixture
{
    std::stringstream in;
    std::stringstream out;
    CShapeController shapeController;
    ShapeControllerFixture()
        :shapeController(in, out)
    {}
};

BOOST_FIXTURE_TEST_SUITE(ShapeController_class, ShapeControllerFixture)

    BOOST_AUTO_TEST_CASE(can_handle_line)
    {
        in << "Line 0 0 0 5 010101";
        std::stringstream command;
        BOOST_CHECK(shapeController.GetCommand(command));
        BOOST_CHECK(shapeController.HandleCommand(command));
        shapeController.PrintShapes();
        std::stringstream lineInfo;
        std::stringstream expectedOut;
        lineInfo << "Line:" << "\n"
            << "  Area = 0" << "\n"
            << "  Outline color = 010101" << "\n"
            << "  Perimeter = 5" << "\n"
            << "  Start point = (0.000000, 0.000000)" << "\n"
            << "  End point = (0.000000, 5.000000)" << "\n" << "\n";
        expectedOut << lineInfo.str()
            << "Фигура с максимальной площадью: \n"
            << lineInfo.str()
            << "Фигура с минимальным периметром: \n"
            << lineInfo.str();
        BOOST_CHECK_EQUAL(out.str(), expectedOut.str());
    }
    BOOST_AUTO_TEST_CASE(can_handle_rectangle)
    {
        in << "Rectangle 0 0 5 10 010101 FAFAFA";
        std::stringstream command;
        BOOST_CHECK(shapeController.GetCommand(command));
        BOOST_CHECK(shapeController.HandleCommand(command));
        shapeController.PrintShapes();
        std::stringstream RectangleInfo;
        std::stringstream expectedOut;
        RectangleInfo << "Rectangle:" << "\n"
            << "  Area = " << (5 * 10) << "\n"
            << "  Outline color = 010101" << "\n"
            << "  Fill color = fafafa" << "\n"
            << "  Perimeter = " << ((5 + 10) * 2) << "\n"
            << "  Left-Top point = (0.000000, 0.000000)" << "\n"
            << "  Right-Bottom point = (5.000000, 10.000000)" << "\n"
            << "  Width = 5"<< "\n"
            << "  Height = 10" << "\n" << "\n";
        expectedOut << RectangleInfo.str()
            << "Фигура с максимальной площадью: \n"
            << RectangleInfo.str()
            << "Фигура с минимальным периметром: \n"
            << RectangleInfo.str();
        BOOST_CHECK_EQUAL(out.str(), expectedOut.str());
    }
    BOOST_AUTO_TEST_CASE(can_handle_triangle)
    {
        in << "Triangle 0 0 0 5 5 0 010101 FAFAFA";
        std::stringstream command;
        BOOST_CHECK(shapeController.GetCommand(command));
        BOOST_CHECK(shapeController.HandleCommand(command));
        shapeController.PrintShapes();
        std::stringstream triangleInfo;
        std::stringstream expectedOut;
        triangleInfo << "Triangle:" << "\n"
            << "  Area = " << GetArea(CPoint({ 0, 0 }), CPoint({ 0, 5 }), CPoint({ 5, 0 })) << "\n"
            << "  Outline color = 010101" << "\n"
            << "  Fill color = fafafa" << "\n"
            << "  Perimeter = " << GetPerimeter(CPoint({ 0, 0 }), CPoint({ 0, 5 }), CPoint({ 5, 0 })) << "\n"
            << "  Vertex 1 = (0.000000, 0.000000)" << "\n"
            << "  Vertex 2 = (0.000000, 5.000000)" << "\n"
            << "  Vertex 3 = (5.000000, 0.000000)" << "\n"
            << "  Side length 1 = " << GetSideLength(CPoint({ 0, 0 }), CPoint({ 0, 5 })) << "\n"
            << "  Side length 2 = " << GetSideLength(CPoint({ 0, 5 }), CPoint({ 5, 0 })) << "\n"
            << "  Side length 3 = " << GetSideLength(CPoint({ 0, 0 }), CPoint({ 5, 0 })) << "\n" << "\n";
        expectedOut << triangleInfo.str()
            << "Фигура с максимальной площадью: \n"
            << triangleInfo.str()
            << "Фигура с минимальным периметром: \n"
            << triangleInfo.str();
        BOOST_CHECK_EQUAL(out.str(), expectedOut.str());
    }
    BOOST_AUTO_TEST_CASE(can_handle_circle)
    {
        in << "Circle 0 0 5 010101 FAFAFA";
        std::stringstream command;
        BOOST_CHECK(shapeController.GetCommand(command));
        BOOST_CHECK(shapeController.HandleCommand(command));
        shapeController.PrintShapes();
        std::stringstream circleInfo;
        std::stringstream expectedOut;
        circleInfo << "Circle:" << "\n"
            << "  Area = " << (boost::math::constants::pi<float>() * 5.f * 5.f) << "\n"
            << "  Outline color = 010101" << "\n"
            << "  Fill color = fafafa" << "\n"
            << "  Circumference = " << (boost::math::constants::two_pi<float>() * 5.f) << "\n"
            << "  Center point = (0.000000, 0.000000)" << "\n"
            << "  Radius = 5" << "\n" << "\n";
        expectedOut << circleInfo.str()
            << "Фигура с максимальной площадью: \n"
            << circleInfo.str()
            << "Фигура с минимальным периметром: \n"
            << circleInfo.str();
        BOOST_CHECK_EQUAL(out.str(), expectedOut.str());
    }
    BOOST_AUTO_TEST_CASE(cant_get_command_from_empty_line)
    {
        in << "";
        std::stringstream command;
        BOOST_CHECK(!shapeController.GetCommand(command));
    }
    BOOST_AUTO_TEST_CASE(cant_print_empty_shapes)
    {
        BOOST_CHECK(!shapeController.PrintShapes());
    }
    BOOST_AUTO_TEST_CASE(cant_handle_unknown_command)
    {
        in << "UnknownShape";
        std::stringstream command;
        BOOST_CHECK(shapeController.GetCommand(command));
        BOOST_CHECK(!shapeController.HandleCommand(command));
    }
    BOOST_AUTO_TEST_CASE(cant_handle_empty_command)
    {
        std::stringstream command("");
        BOOST_CHECK(!shapeController.HandleCommand(command));
    }
    BOOST_AUTO_TEST_CASE(cant_handle_command_if_arguments_count_not_enough)
    {
        in << "Line";
        std::stringstream command;
        BOOST_CHECK(shapeController.GetCommand(command));
        BOOST_CHECK(!shapeController.HandleCommand(command));
    }

BOOST_AUTO_TEST_SUITE_END()