#include <iostream>
#include <fstream>

using namespace std;

//�������� ������������� ���������� ������� ���������
bool IsCorrectProgramUsing(int argc)
{
    return (argc == 5);
}

//�������� ������������� �����
bool IsFileExists(char *fileName)
{
    ifstream file(fileName);
    return file.good();
}

//�������� ����� �� �������
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

    return 0;
}