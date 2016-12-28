#include "stdafx.h"
#include "ShapeController.h"

CShapeController::CShapeController(std::istream &in, std::ostream &out)
    : m_in(in)
    , m_out(out)
    , m_actions({
        { "line", std::bind(&CShapeController::CreateLine, this, std::placeholders::_1, std::placeholders::_2) },
        { "triangle", std::bind(&CShapeController::CreateTriangle, this, std::placeholders::_1, std::placeholders::_2) },
        { "rectangle", std::bind(&CShapeController::CreateRectangle, this, std::placeholders::_1, std::placeholders::_2) },
        { "circle", std::bind(&CShapeController::CreateCircle, this, std::placeholders::_1, std::placeholders::_2) }
    })
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

size_t CShapeController::GetArgCount(std::stringstream const& arguments) const
{
    std::vector<std::string> argumentsVector;
    boost::split(argumentsVector, arguments.str(), boost::is_any_of(" "));
    return argumentsVector.size();
}

bool CShapeController::GetCommand(std::stringstream &command) const
{
    command.clear();
    command.str("");
    std::string commandLine;
    if (!getline(m_in, commandLine))
    {
        return false;
    }
    std::string lowerCasedCommandLine;
    lowerCasedCommandLine.resize(commandLine.length());
    std::transform(commandLine.begin(), commandLine.end(), lowerCasedCommandLine.begin(), ::towlower);
    command << lowerCasedCommandLine;
    return true;
}

bool CShapeController::HandleCommand(std::stringstream &command)
{
    if (command.str().empty())
    {
        return false;
    }
    std::string action;
    command >> action;
    if (REQUIRED_COMMAND_ARG_COUNT.find(action) == REQUIRED_COMMAND_ARG_COUNT.end())
    {
        m_out << "Неизвестная команда: \"" << action << "\"\n";
        return false;
    }
    if (REQUIRED_COMMAND_ARG_COUNT.at(action) != GetArgCount(command) - 1)
    {
        m_out << "Команда \"" << action << "\" требует " << REQUIRED_COMMAND_ARG_COUNT.at(action) << " аргумент(ов) \n";
        return false;
    }

    std::shared_ptr<CShape> shape;
    if (!m_actions[action](command, shape))
    {
        m_out << "Ошибка добавления фигуры: " << action << "\n";
        return false;
    }
    m_shapes.push_back(shape);
    
    return true;
}

bool CShapeController::CreateLine(std::istream & args, std::shared_ptr<CShape> &shape) const
{
    std::shared_ptr<CLineSegment> line;
    if (args >> line)
    {
        shape = line;
        return true;
    }
    return false;
}

bool CShapeController::CreateTriangle(std::istream & args, std::shared_ptr<CShape> &shape) const
{
    std::shared_ptr<CTriangle> triangle;
    if (args >> triangle)
    {
        shape = triangle;
        return true;
    }
    return false;
}

bool CShapeController::CreateRectangle(std::istream & args, std::shared_ptr<CShape> &shape) const
{
    std::shared_ptr<CRectangle> rectangle;
    if (args >> rectangle)
    {
        shape = rectangle;
        return true;
    }
    return false;
}

bool CShapeController::CreateCircle(std::istream & args, std::shared_ptr<CShape> &shape) const
{
    std::shared_ptr<CCircle> circle;
    if (args >> circle)
    {
        shape = circle;
        return true;
    }
    return false;
}

std::shared_ptr<CShape> CShapeController::GetMaxAreaShape(std::vector<std::shared_ptr<CShape>> const& shapes) const
{
    if (shapes.empty())
    {
        return nullptr;
    }
    return *min_element(shapes.begin(), shapes.end(),
        [&](std::shared_ptr<CShape> const& shape1, std::shared_ptr<CShape> const& shape2)
        {
            return shape1->GetArea() > shape2->GetArea();
        });
}

std::shared_ptr<CShape> CShapeController::GetMinPerimeterShape(std::vector<std::shared_ptr<CShape>> const& shapes) const
{
    if (shapes.empty())
    {
        return nullptr;
    }
    return *min_element(shapes.begin(), shapes.end(),
        [&](std::shared_ptr<CShape> const& shape1, std::shared_ptr<CShape> const& shape2)
        {
            return shape1->GetPerimeter() < shape2->GetPerimeter();
        });
}

bool CShapeController::PrintShapes() const
{
    if (m_shapes.empty())
    {
        return false;
    }

    for (auto shape : m_shapes)
    {
        m_out << shape->ToString() << "\n";
    }
    m_out << "Фигура с максимальной площадью: \n"
        << GetMaxAreaShape(m_shapes)->ToString() << "\n";
    m_out << "Фигура с минимальным периметром: \n"
        << GetMinPerimeterShape(m_shapes)->ToString() << "\n";
    return true;
}

void CShapeController::HandleEvents(CCanvas &canvas)
{
    sf::Event event;
    while (canvas.PollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            canvas.Close();
    }
}

void CShapeController::DrawShapes()
{
    CCanvas canvas(sf::VideoMode(800, 600), "Shapes");
    canvas.AddShapes(m_shapes);
    canvas.Clear(sf::Color::White);
    canvas.DrawShapes();
    canvas.Display();
    while (canvas.IsOpen())
    {
        HandleEvents(canvas);
    }
}