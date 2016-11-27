#include "stdafx.h"
#include "fileValidation.h"

//�������� ������������� �����
bool IsFileExists(std::ifstream &file)
{
    return file.good();
}

//�������� ����� �� �������
bool IsFileEmpty(std::ifstream &file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}

//�������� ����� ����� �� ������������� � ������� � �� ��������;
bool IsValidInputFile(std::string const& inputFileName, std::ifstream &inputFile, std::string &errorMessage)
{
    if (!IsFileExists(inputFile))
    {
        errorMessage = "File \"" + inputFileName + "\" not exists" + "\n";
        return false;
    }
    if (IsFileEmpty(inputFile))
    {
        errorMessage = "File \"" + inputFileName + "\" is empty" + "\n";
        return false;
    }
    return true;
}