#include <iostream>
#include <fstream>

using namespace std;

//Проверка достаточности параметров запуска программы
bool IsCorrectProgramUsing(int argc)
{
    return (argc == 5);
}

//Проверка существования файла
bool IsFileExists(char *fileName)
{
    ifstream file(fileName);
    return file.good();
}

//Проверка файла на пустоту
bool IsFileEmpty(ifstream &file)
{
    return file.peek() == ifstream::traits_type::eof();
}

int main(int argc, char* argv[])
{
    if (!IsCorrectProgramUsing(argc))
    {
        cout << "replace.exe using: <input file> <output file> <search string> <replace string>" << "\n";
        return 1;
    }
    if (!IsFileExists(argv[1]))
    {
        cout << "File \"" << argv[1] << "\" not exists" << "\n";
        return 1;
    }
    ifstream inputFile(argv[1]);
    if (IsFileEmpty(inputFile))
    {
        cout << "File \"" << argv[1] << "\" is empty" << "\n";
        return 1;
    }
    ofstream outputFile(argv[2]);
    if (!outputFile.is_open())
    {
        cout << "Failed to open " << argv[2] << " for writing" << "\n";
        return 1;
    }
    unsigned int searchStringLen = strlen(argv[3]);
    unsigned int replaceStringLen = strlen(argv[4]);
    if (searchStringLen == 0)
    {
        cout << "Search string isn't set" << "\n";
        return 1;
    }
    if (replaceStringLen == 0)
    {
        cout << "Replace string isn't set" << "\n";
        return 1;
    }

    return 0;
}