#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define MATRIX_HEIGHT 3
#define MATRIX_WIDTH 3

typedef vector<vector<double>> matrix;

//Проверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
    return (argc == 2);
}

//Проверка существования файла
bool IsFileExists(ifstream &file)
{
    return file.good();
}

//Проверка файла на пустоту
bool IsFileEmpty(ifstream &file)
{
    return file.peek() == ifstream::traits_type::eof();
}

//Проверка файла ввода на существование и наличие в нём символов;
bool IsValidInputFile(char* inputFileName, ifstream &inputFile)
{
    if (!IsFileExists(inputFile))
    {
        cout << "File \"" << inputFileName << "\" not exists" << "\n";
        return false;
    }
    if (IsFileEmpty(inputFile))
    {
        cout << "File \"" << inputFileName << "\" is empty" << "\n";
        return false;
    }
    return true;
}

//Чтение матрицы из файла
matrix ReadMatrixFromFile(ifstream & inputFile, unsigned int matrixHeight, unsigned int matrixWidth)
{
    matrix result(matrixWidth);
    for (unsigned int i = 0; i < result.size(); ++i)
    {
        for (unsigned int j = 0; j < matrixHeight; ++j)
        {
            result.at(i).push_back(0);
        }
    }

    double matrixElement = 0;
    for (unsigned int i = 0; i < result.size(); ++i)
    {
        for (unsigned int j = 0; j < result.at(i).size(); ++j)
        {
            inputFile >> matrixElement;
            result.at(j).at(i) = matrixElement;
        }
    }
    return result;
}

//Вывод матрицы
void PrintMatrix(const matrix& matrix)
{
    for (unsigned int i = 0; i < matrix.size(); ++i)
    {
        for (unsigned int j = 0; j < matrix.at(i).size(); ++j)
        {
            printf("%.3f  ", matrix.at(j).at(i));
        }
        printf("\n");
    }
}

//Получение определителя матрицы 3x3
double GetMatrix3x3Determinant(const matrix& matrix, bool &wasError)
{
    if (matrix.size() != 3 || matrix.at(0).size() != 3)
    {
        wasError = true;
        return 0;
    }
    return matrix[0][0] * matrix[1][1] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1]
         - matrix[0][1] * matrix[1][0] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0]
         + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0];
}

int main(int argc, char* argv[])
{
    if (!IsValidArgumentsCount(argc))
    {
        cout << "invert.exe <matrix file>" << "\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!IsValidInputFile(argv[1], inputFile))
    {
        return 1;
    }
    
    bool wasError = false;

    matrix matrix = ReadMatrixFromFile(inputFile, MATRIX_HEIGHT, MATRIX_WIDTH);

    double matrixDeterminant = GetMatrix3x3Determinant(matrix, wasError);
    if (wasError)
    {
        cout << "Matrix 3x3 expected" << "\n";
        return 1;
    }
    if (matrixDeterminant == 0)
    {
        cout << "The inverted matrix does not exist" << "\n";
        return 1;
    }

    return 0;
}