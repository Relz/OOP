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

//�������� ������������� ���������� ������� ���������
bool IsValidArgumentsCount(int argc)
{
    return (argc == ARG_COUNT);
}

bool AddLine(istream & args, vector<shared_ptr<CShape>> &shapes)
{
    CPoint startPoint;
    CPoint endPoint;
    string outlineColor;
    if (args >> startPoint.x && args >> startPoint.y && args >> endPoint.x && args >> endPoint.y && args >> outlineColor)
    {
        shapes.push_back(make_shared<CLineSegment>(startPoint, endPoint, outlineColor));
        return true;
    }
    return false;
}

bool AddTriangle(istream & args, vector<shared_ptr<CShape>> &shapes)
{
    CPoint vertex1;
    CPoint vertex2;
    CPoint vertex3;
    string outlineColor;
    string fillColor;
    if (args >> vertex1.x && args >> vertex1.y 
        && args >> vertex2.x && args >> vertex2.y 
        && args >> vertex3.x && args >> vertex3.y
        && args >> outlineColor && args >> fillColor)
    {
        shapes.push_back(make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor));
        return true;
    }
    return false;
}

bool AddRectangle(istream & args, vector<shared_ptr<CShape>> &shapes)
{
    CPoint leftTop;
    double width;
    double height;
    string outlineColor;
    string fillColor;
    if (args >> leftTop.x && args >> leftTop.y
        && args >> width && args >> height
        && args >> outlineColor && args >> fillColor)
    {
        shapes.push_back(make_shared<CRectangle>(leftTop, width, height, outlineColor, fillColor));
        return true;
    }
    return false;
}

bool AddCircle(istream & args, vector<shared_ptr<CShape>> &shapes)
{
    CPoint center;
    double radius;
    string outlineColor;
    string fillColor;
    if (args >> center.x && args >> center.y
        && args >> radius && args >> outlineColor && args >> fillColor)
    {
        shapes.push_back(make_shared<CCircle>(center, radius, outlineColor, fillColor));
        return true;
    }
    return false;
}

shared_ptr<CShape> GetMaxAreaShape(vector<shared_ptr<CShape>> const& shapes)
{
    return *min_element(shapes.begin(), shapes.end(), 
        [&](shared_ptr<CShape> const& shape1, shared_ptr<CShape> const& shape2)
        {
            return shape1->GetArea() > shape2->GetArea();
        });
}

shared_ptr<CShape> GetMinPerimeterShape(vector<shared_ptr<CShape>> const& shapes)
{
    return *min_element(shapes.begin(), shapes.end(), 
        [&](shared_ptr<CShape> const& shape1, shared_ptr<CShape> const& shape2)
        {
            return shape1->GetPerimeter() < shape2->GetPerimeter();
        });
}

void PrintShapes(vector<shared_ptr<CShape>> &shapes)
{
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

    map<string, function<bool(istream & args, vector<shared_ptr<CShape>> &shapes)>> actions
    {
        {"Line", bind(&AddLine, _1, _2)},
        {"Triangle", bind(&AddTriangle, _1, _2)},
        {"Rectangle", bind(&AddRectangle, _1, _2)},
        {"Circle", bind(&AddCircle, _1, _2)}
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
            if (it != actions.end())
            {
                if (!it->second(ss, shapes))
                {
                    cout << "Line #" << currentLine << ": Unable to parse line: " << line << "\n";
                }
            }
            else
            {
                cout << "Line #" << currentLine << ": Unknown shape: " << action << "\n";
            }
        }
    }

    PrintShapes(shapes);
    return 0;
}