#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const unsigned ARG_COUNT_MIN = 2;
const unsigned ARG_COUNT_MAX = 3;

const unsigned MAP_WIDTH_MAX = 256;
const unsigned MAP_HEIGHT_MAX = 256;

//Проверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
    return (argc >= ARG_COUNT_MIN && argc <= ARG_COUNT_MAX);
}

//Проверка существования файла
bool IsFileExists(const ifstream &file)
{
    return file.good();
}

//Проверка файла на пустоту
bool IsFileEmpty(ifstream &file)
{
    return file.peek() == ifstream::traits_type::eof();
}

//Проверка:
//  a)файла ввода на существование и наличие в нём символов;
//  b)файла вывода на возможность записи.
bool IsValidInputFile(char *inputFileName, ifstream &inputFile)
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

int main(int argc, char* argv[])
{
    if (!IsValidArgumentsCount(argc))
    {
        cout << argv[0] << " using: <input file> [<output file>]" << "\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!IsValidInputFile(argv[1], inputFile))
    {
        return 1;
    }

    ofstream outputFile;
    if (argc == ARG_COUNT_MAX)
    {
        outputFile.open(argv[2]);
        if (!outputFile.is_open())
        {
            cout << "Failed to open " << argv[2] << " for writing" << "\n";
            return false;
        }
    }

    inputFile.close();

    if (argc == ARG_COUNT_MAX)
    {
        outputFile.close();
    }

    return 0;
}