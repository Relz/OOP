#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define MIN_NOTATION 2
#define MAX_NOTATION 36

//Проверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
    return (argc == 4);
}

//Проверка системы счисления на диапазон от 2 до 36
bool IsValidNotation(int notation)
{
    return (notation >= MIN_NOTATION && notation <= MAX_NOTATION);
}
        
int main(int argc, char* argv[])
{
    if (!IsValidArgumentsCount(argc))
    {
        cout << "radix.exe <source notation> <destination notation> <value>" << "\n";
        return 1;
    }

    string srcNotationStr = argv[1];
    if (srcNotationStr == "")
    {
        cout << "Error: source notation not specified" << "\n";
        return 1;
    }

    string dstNotationStr = argv[2];
    if (dstNotationStr == "")
    {
        cout << "Error: destination notation not specified" << "\n";
        return 1;
    }

    string valueStr = argv[3];
    if (valueStr == "")
    {
        cout << "Error: value not specified" << "\n";
        return 1;
    }

    int srcNotation, dstNotation;

    stringstream(srcNotationStr) >> srcNotation;
    stringstream(dstNotationStr) >> dstNotation;

    if (!IsValidNotation(srcNotation))
    {
        cout << "Error: invalid source notation. Supported values: " << MIN_NOTATION << ".." << MAX_NOTATION << "\n";
        return 1;
    }

    if (!IsValidNotation(dstNotation))
    {
        cout << "Error: invalid destination notation. Supported values: " << MIN_NOTATION << ".." << MAX_NOTATION << "\n";
        return 1;
    }


}