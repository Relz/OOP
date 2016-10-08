#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const unsigned ARG_COUNT = 2;

const unsigned MATRIX_HEIGHT = 3;
const unsigned MATRIX_WIDTH = 3;

//Проверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
    return (argc == ARG_COUNT);
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
bool ReadMatrixFromFile(ifstream & inputFile, double matrix[MATRIX_HEIGHT][MATRIX_WIDTH])
{
    double matrixElement = 0;
    for (unsigned int i = 0; i < MATRIX_HEIGHT; ++i)
    {
        for (unsigned int j = 0; j < MATRIX_WIDTH; ++j)
        {
            if (inputFile >> matrixElement)
            {
                matrix[j][i] = matrixElement;
            }
            else
            {
                cout << "Not enough elements in input file to fill matrix 3x3" << "\n";
                return false;
            }
        }
    }
    return true;
}

//Вывод матрицы MATRIX_WIDTH x MATRIX_HEIGHT
void PrintMatrix(const double matrix[MATRIX_HEIGHT][MATRIX_WIDTH])
{
    for (unsigned int i = 0; i < MATRIX_HEIGHT; ++i)
    {
        for (unsigned int j = 0; j < MATRIX_WIDTH; ++j)
        {
            cout << fixed << setprecision(3) << matrix[j][i] << ' ';
        }
        cout << "\n";
    }
}

//Получение определителя матрицы 2x2
double GetMatrix2x2Determinant(const double matrix[2][2])
{
    return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
}

//Получение определителя матрицы 3x3
double GetMatrix3x3Determinant(const double matrix[MATRIX_HEIGHT][MATRIX_WIDTH])
{
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
         - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
         + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

//Получение минора элемента матрицы
void GetMinor(const double inputMatrix[MATRIX_HEIGHT][MATRIX_WIDTH], double outputMatrix[MATRIX_HEIGHT][MATRIX_WIDTH], const unsigned int &line, const unsigned int &column)
{
    unsigned int currentMinorLine = 0;
    unsigned int currentMinorColumn = 0;
    double matrix2x2[2][2];

    for (unsigned int i = 0; i < MATRIX_HEIGHT; ++i)
    {
        for (unsigned int j = 0; j < MATRIX_WIDTH; ++j)
        {
            if (i != column && j != line)
            {
                matrix2x2[currentMinorColumn][currentMinorLine] = inputMatrix[j][i];
                currentMinorColumn++;
            }
        }
        if (i != column)
        {
            currentMinorLine++;
            currentMinorColumn = 0;
        }
    }
    outputMatrix[line][column] = GetMatrix2x2Determinant(matrix2x2);
}

//Получение матрицы алгебраических дополнений
void GetAlgebraicAdditionsMatrix(const double inputMatrix[MATRIX_HEIGHT][MATRIX_WIDTH], double outputMatrix[MATRIX_HEIGHT][MATRIX_WIDTH])
{
    for (unsigned int i = 0; i < MATRIX_HEIGHT; ++i)
    {
        for (unsigned int j = 0; j < MATRIX_WIDTH; ++j)
        {
            GetMinor(inputMatrix, outputMatrix, j, i);
            outputMatrix[j][i] = outputMatrix[j][i] * pow(-1, j + i);
        }
    }
}

//Транспонирование матрицы
void TransposeMatrix(const double inputMatrix[MATRIX_HEIGHT][MATRIX_WIDTH], double outputMatrix[MATRIX_HEIGHT][MATRIX_WIDTH])
{
    GetAlgebraicAdditionsMatrix(inputMatrix, outputMatrix);
    for (unsigned int i = 0; i < MATRIX_HEIGHT; ++i)
    {
        for (unsigned int j = i; j < MATRIX_WIDTH; ++j)
        {
            double tmp = outputMatrix[i][j];
            outputMatrix[i][j] = outputMatrix[j][i];
            outputMatrix[j][i] = tmp;
        }
    }
}

//Получение обратной матрицы
void InvertMatrix(const double inputMatrix[MATRIX_HEIGHT][MATRIX_WIDTH], double outputMatrix[MATRIX_HEIGHT][MATRIX_WIDTH], double matrixDeterminant)
{
    TransposeMatrix(inputMatrix, outputMatrix);
    for (unsigned int i = 0; i < MATRIX_HEIGHT; ++i)
    {
        for (unsigned int j = 0; j < MATRIX_WIDTH; ++j)
        {
            outputMatrix[j][i] = outputMatrix[j][i] / matrixDeterminant;
        }
    }
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

    double matrix[MATRIX_HEIGHT][MATRIX_WIDTH];
    if (!ReadMatrixFromFile(inputFile, matrix))
    {
        return 1;
    }

    double matrixDeterminant = GetMatrix3x3Determinant(matrix);
    if (matrixDeterminant == 0)
    {
        cout << "The inverted matrix does not exist" << "\n";
        return 1;
    }

    double invertedMatrix[MATRIX_HEIGHT][MATRIX_WIDTH];
    InvertMatrix(matrix, invertedMatrix, matrixDeterminant);
    PrintMatrix(invertedMatrix);

    return 0;
}