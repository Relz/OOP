#include "stdafx.h"
#include "fileValidation.h"
#include "Point.h"
#include "IShape.h"
#include "Shape.h"
#include "LineSegment.h"
#include "ISolidShape.h"
#include "SolidShape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;
using namespace std::placeholders;

const unsigned ARG_COUNT = 2;

//Проверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
    return (argc == ARG_COUNT);
}

bool CreateLine(istream & args, shared_ptr<CShape> &shape)
{
    shared_ptr<CLineSegment> line;
    if (args >> line)
    {
        shape = line;
        return true;
    }
    return false;
}

bool CreateTriangle(istream & args, shared_ptr<CShape> &shape)
{
    shared_ptr<CTriangle> triangle;
    if (args >> triangle)
    {
        shape = triangle;
        return true;
    }
    return false;
}

bool CreateRectangle(istream & args, shared_ptr<CShape> &shape)
{
    shared_ptr<CRectangle> rectangle;
    if (args >> rectangle)
    {
        shape = rectangle;
        return true;
    }
    return false;
}

bool CreateCircle(istream & args, shared_ptr<CShape> &shape)
{
    shared_ptr<CCircle> circle;
    if (args >> circle)
    {
        shape = circle;
        return true;
    }
    return false;
}

shared_ptr<CShape> GetMaxAreaShape(vector<shared_ptr<CShape>> const& shapes)
{
    if (shapes.empty())
    {
        return nullptr;
    }
    return *min_element(shapes.begin(), shapes.end(), 
        [&](shared_ptr<CShape> const& shape1, shared_ptr<CShape> const& shape2)
        {
            return shape1->GetArea() > shape2->GetArea();
        });
}

shared_ptr<CShape> GetMinPerimeterShape(vector<shared_ptr<CShape>> const& shapes)
{
    if (shapes.empty())
    {
        return nullptr;
    }
    return *min_element(shapes.begin(), shapes.end(), 
        [&](shared_ptr<CShape> const& shape1, shared_ptr<CShape> const& shape2)
        {
            return shape1->GetPerimeter() < shape2->GetPerimeter();
        });
}

void PrintShapes(vector<shared_ptr<CShape>> const& shapes)
{
    if (shapes.empty())
    {
        return;
    }

    for (auto shape : shapes)
    {
        cout << shape->ToString() << "\n";
    }
    cout << "Shape with maximum area: \n"
        << GetMaxAreaShape(shapes)->ToString() << "\n";
    cout << "Shape with minimum perimeter: \n"
        << GetMinPerimeterShape(shapes)->ToString() << "\n";
}

int main(int argc, char * argv[])
{
    if (!IsValidArgumentsCount(argc))
    {
        cout << "Shape.exe <input file>" << "\n";
        return 1;
    }

    string errorMessage;
    ifstream inputFile(argv[1]);
    if (!IsValidInputFile(argv[1], inputFile, errorMessage))
    {
        cerr << errorMessage;
        return 1;
    }

    map<string, function<bool(istream & args, shared_ptr<CShape> &shape)>> actions = 
    {
        {"Line", bind(&CreateLine, _1, _2)},
        {"Triangle", bind(&CreateTriangle, _1, _2)},
        {"Rectangle", bind(&CreateRectangle, _1, _2)},
        {"Circle", bind(&CreateCircle, _1, _2)}
    };

    size_t currentLine = 0;
    vector<shared_ptr<CShape>> shapes;
    stringstream ss;
    string line;
    while (getline(inputFile, line))
    {
        currentLine++;
        ss.clear();
        ss << line;
        string action;
        if (ss >> action)
        {
            auto it = actions.find(action);
            if (it == actions.end())
            {
                cout << "Line #" << currentLine << ": Unknown shape: " << action << "\n";
                continue;
            }
            shared_ptr<CShape> shape;
            if (!it->second(ss, shape))
            {
                cout << "Line #" << currentLine << ": Unable to parse line: " << line << "\n";
                continue;
            }
            shapes.push_back(shape);
        }
    }

    PrintShapes(shapes);
    return 0;
}