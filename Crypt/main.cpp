#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const unsigned ARG_COUNT = 4;

//�������� ������������� ���������� ������� ���������
bool IsValidArgumentsCount(int argc)
{
    return (argc == ARG_COUNT);
}

//�������� ������������� �����
bool IsFileExists(const ifstream &file)
{
    return file.good();
}

//�������� ����� �� �������
bool IsFileEmpty(ifstream &file)
{
    return file.peek() == ifstream::traits_type::eof();
}

//��������:
//  a)����� ����� �� ������������� � ������� � �� ��������;
//  b)����� ������ �� ����������� ������.
bool IsValidInputOutputFiles(char *inputFileName, char *outputFileName, ifstream &inputFile, const ofstream &outputFile)
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
    if (!outputFile.is_open())
    {
        cout << "Failed to open " << outputFileName << " for writing" << "\n";
        return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    if (!IsValidArgumentsCount(argc))
    {
        cout << argv[0] << " using: <input file> <output file> <key>" << "\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);
    if (!IsValidInputOutputFiles(argv[1], argv[2], inputFile, outputFile))
    {
        return 1;
    }

    return 0;
}