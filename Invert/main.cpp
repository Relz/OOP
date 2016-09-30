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

//Создание матрицы, заполненной нулями
matrix CreateMatrix(unsigned int rows, unsigned int columns)
{
    matrix result(rows);
    for (unsigned int i = 0; i < result.size(); ++i)
    {
        for (unsigned int j = 0; j < columns; ++j)
        {
            result.at(i).push_back(0);
        }
    }
    return result;
}

//Чтение матрицы из файла
matrix ReadMatrixFromFile(ifstream & inputFile, unsigned int matrixHeight, unsigned int matrixWidth)
{
    matrix result = CreateMatrix(matrixWidth, matrixHeight);

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

//Получение определителя матрицы 2x2
double GetMatrix2x2Determinant(const matrix& inputMatrix, bool &wasError)
{
    if (inputMatrix.size() != 2 || inputMatrix.at(0).size() != 2)
    {
        wasError = true;
        return 0;
    }
    return inputMatrix[0][0] * inputMatrix[1][1] - inputMatrix[1][0] * inputMatrix[0][1]);
}

//Получение определителя матрицы 3x3
double GetMatrix3x3Determinant(const matrix& inputMatrix, bool &wasError)
{
    if (inputMatrix.size() != 3 || inputMatrix.at(0).size() != 3)
    {
        wasError = true;
        return 0;
    }
    return inputMatrix[0][0] * (inputMatrix[1][1] * inputMatrix[2][2] - inputMatrix[1][2] * inputMatrix[2][1])
        - inputMatrix[0][1] * (inputMatrix[1][0] * inputMatrix[2][2] + inputMatrix[1][2] * inputMatrix[2][0])
        + inputMatrix[0][2] * (inputMatrix[1][0] * inputMatrix[2][1] - inputMatrix[1][1] * inputMatrix[2][0]);
}

//Получение минора элемента матрицы
matrix getMinor(const matrix &inputMatrix, const unsigned int &row, const unsigned int &column)
{
    matrix result = CreateMatrix(2, 2);
    unsigned int currentMinorLine = 0;
    unsigned int currentMinorColumn = 0;
    bool minorFilled = false;

    for (unsigned int i = 0; i < inputMatrix.size(); ++i)
    {
        for (unsigned int j = 0; j < inputMatrix.at(i).size(); ++j)
        {
            if (i != column && j != row)
            {
                if (currentMinorColumn > 1)
                {
                    currentMinorColumn = 0;
                    if (currentMinorLine > 1)
                    {
                        minorFilled = true;
                        break;
                    }
                    currentMinorLine++;
                }
                result.at(currentMinorColumn).at(currentMinorLine) = inputMatrix.at(j).at(i);
                currentMinorColumn++;
            }
        }
        if (minorFilled)
        {
            break;
        }
    }
    return result;
}

//Получение матрицы миноров
matrix getMinorMatrix(const matrix &inputMatrix)
{
    matrix result = inputMatrix;
    for (unsigned int i = 0; i < inputMatrix.size(); ++i)
    {
        for (unsigned int j = 0; j < inputMatrix.at(i).size(); ++j)
        {
            matrix minor = getMinor(inputMatrix, j, i);
            PrintMatrix(minor);
            //inputMatrix.at(j).at(i) = 
        }
    }
    return result;
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

    getMinorMatrix(matrix);

    return 0;
}