#include "stdafx.h"
#include "fileValidation.h"

//Проверка существования файла
bool IsFileExists(std::ifstream &file)
{
    return file.good();
}

//Проверка файла на пустоту
bool IsFileEmpty(std::ifstream &file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}

//Проверка файла ввода на существование и наличие в нём символов;
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