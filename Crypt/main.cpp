#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const unsigned ARG_COUNT = 4;

const unsigned KEY_MIN = 0;
const unsigned KEY_MAX = 255;

//Проверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
    return (argc == ARG_COUNT);
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

//Функция проверки параметра строки key на допустимость символов
bool IsValidKeyStr(string keyStr)
{
    for (unsigned i = 0; i < keyStr.length(); ++i)
    {
        if (keyStr[i] < '0' || keyStr[i] > '9')
        {
            return false;
        }
    }
    return true;
}

//Функция переводит символ в цифру
unsigned char CharToDigit(char ch)
{
    unsigned char digit = 0;
    if (ch >= '0' && ch <= '9')
    {
        digit = ch - '0';
    }
    return digit;
}

//Функция переводит строку в положительное целочисленное число от 0 до 255
unsigned char StrToUnsignedChar(const string &str, bool &wasError)
{
    unsigned char result = 0;
    for (unsigned i = 0; i < str.length(); ++i)
    {
        unsigned char digit = CharToDigit(str[i]);
        if (result > (UCHAR_MAX - digit) / 10)
        {
            wasError = true;
            return 0;
        }
        result = result * 10 + digit;
    }
    return result;
}

bool IsValidKey(unsigned char key)
{
    return key >= KEY_MIN && key <= KEY_MAX;
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

    bool wasError = false;
    string keyStr = argv[3];
    if (keyStr == "")
    {
        cout << "Error: key not specified" << "\n";
        return 1;
    }
    if (!IsValidKeyStr(keyStr))
    {
        cout << "Error: invalid key. Supported values: " << KEY_MIN << ".." << KEY_MAX << "\n";
        return 1;
    }

    unsigned char key = StrToUnsignedChar(keyStr, wasError);
    if (wasError)
    {
        cout << "Error: overflow, maximum key value = " << UCHAR_MAX << "\n";
        return 1;
    }
    if (!IsValidKey(key))
    {
        cout << "Error: invalid key. Supported values: " << KEY_MIN << ".." << KEY_MAX << "\n";
        return 1;
    }
    cout << (int)key << "\n";

    return 0;
}