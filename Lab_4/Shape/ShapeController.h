#pragma once
#include "stdafx.h"
#include "IShape.h"
#include "Shape.h"
#include "LineSegment.h"
#include "ISolidShape.h"
#include "SolidShape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Canvas.h"
#include <boost/noncopyable.hpp>

class CShapeController : boost::noncopyable
{
public:
    CShapeController(std::istream &in, std::ostream &out);
    bool GetCommand(std::stringstream &command) const;
    bool HandleCommand(std::stringstream &command);
    bool PrintShapes() const;
    void DrawShapes();
private:
    size_t GetArgCount(std::stringstream const& arguments) const;
    bool CreateLine(std::istream & args, std::shared_ptr<CShape> &shape) const;
    bool CreateTriangle(std::istream & args, std::shared_ptr<CShape> &shape) const;
    bool CreateCircle(std::istream & args, std::shared_ptr<CShape> &shape) const;
    bool CreateRectangle(std::istream & args, std::shared_ptr<CShape> &shape) const;
    std::shared_ptr<CShape> GetMaxAreaShape(std::vector<std::shared_ptr<CShape>> const& shapes) const;
    std::shared_ptr<CShape> GetMinPerimeterShape(std::vector<std::shared_ptr<CShape>> const& shapes) const;
    void HandleEvents(CCanvas &canvas);

    std::istream &m_in;
    std::ostream &m_out;
    std::map<std::string, std::function<bool(std::istream & args, std::shared_ptr<CShape> &shape)>> m_actions;
    std::vector<std::shared_ptr<CShape>> m_shapes;

    const std::map<std::string, size_t> REQUIRED_COMMAND_ARG_COUNT = 
    {
        { "line", 5 },
        { "triangle", 8 },
        { "rectangle", 6 },
        { "circle", 5 }
    };
};