#include "stdafx.h"
#include "fileValidation.h"
#include "ShapeController.h"

using namespace std;
using namespace std::placeholders;

const unsigned ARG_COUNT = 2;

int main(int argc, char * argv[])
{
    if (argc != ARG_COUNT)
    {
        cerr << "Shape.exe <input file>" << "\n";
        return 1;
    }

    string errorMessage;
    ifstream inputFile(argv[1]);
    if (!IsValidInputFile(argv[1], inputFile, errorMessage))
    {
        cerr << errorMessage;
        return 1;
    }

    stringstream command;
    CShapeController shapeController(inputFile, cout);
    while (shapeController.GetCommand(command))
    {
        shapeController.HandleCommand(command);
    }
    shapeController.PrintShapes();
    shapeController.DrawShapes();

    return 0;
}