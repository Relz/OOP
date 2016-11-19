#include "stdafx.h"
#include "Point.h"

using namespace std;

const unsigned ARG_COUNT = 2;

//�������� ������������� ���������� ������� ���������
bool IsValidArgumentsCount(int argc)
{
    return (argc == ARG_COUNT);
}

//�������� ������������� �����
bool IsFileExists(ifstream &file)
{
    return file.good();
}

//�������� ����� �� �������
bool IsFileEmpty(ifstream &file)
{
    return file.peek() == ifstream::traits_type::eof();
}

//�������� ����� ����� �� ������������� � ������� � �� ��������;
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

int main(int argc, char * argv[])
{
    if (!IsValidArgumentsCount(argc))
    {
        cout << "Shape.exe <input file>" << "\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!IsValidInputFile(argv[1], inputFile))
    {
        return 1;
    }
    
    return 0;
}