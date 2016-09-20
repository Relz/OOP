#include <iostream>
#include <string>

using namespace std;

//Проверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
    return (argc == 4);
}
        
int main(int argc, char* argv[])
{
    if (!IsValidArgumentsCount(argc))
    {
        cout << "radix.exe <source notation> <destination notation> <value>" << "\n";
        return 1;
    }

    string srcNotation = argv[1];
    if (srcNotation == "")
    {
        cout << "Error: source notation not specified" << "\n";
        return 1;
    }

    string dstNotation = argv[2];
    if (dstNotation == "")
    {
        cout << "Error: destination notation not specified" << "\n";
        return 1;
    }

    string value = argv[3];
    if (value == "")
    {
        cout << "Error: value not specified" << "\n";
        return 1;
    }
}