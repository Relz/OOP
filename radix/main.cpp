#include <iostream>
#include <string>

using namespace std;

#define MIN_NOTATION 2
#define MAX_NOTATION 36

const string & DIGITS = "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ";

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

//Проверка введенного числа на допустимые символы для указанной системы счисления
bool IsValidValue(const string &value, unsigned int radix)
{
    for (unsigned int i = 0; i < value.length(); ++i)
    {
        bool found = false;
        for (unsigned int j = 0; j < radix; ++j)
        {
            if (value[i] == DIGITS[j])
            {
                found = true;
            }
        }
        if (!found)
        {
            return false;
        }
    }
    return true;
}

//Вывод в консоль допустимых символов через запятую для указанной системы счисления
void PrintPossibleRadixSymbols(unsigned int radix)
{
    for (unsigned int i = 0; i < radix; ++i)
    {
        cout << DIGITS[i];
        if (i != radix - 1)
        {
            cout << ", ";
        }
    }
}

//Функция переводит символ в цифру
int CharToInt(char ch)
{
    switch (ch)
    {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C':
            return 12;
        case 'D':
            return 13;
        case 'E':
            return 14;
        case 'F':
            return 15;
        case 'G':
            return 16;
        case 'H':
            return 17;
        case 'I':
            return 18;
        case 'J':
            return 19;
        case 'K':
            return 20;
        case 'L':
            return 21;
        case 'M':
            return 22;
        case 'N':
            return 23;
        case 'O':
            return 24;
        case 'P':
            return 25;
        case 'Q':
            return 26;
        case 'R':
            return 27;
        case 'S':
            return 28;
        case 'T':
            return 29;
        case 'U':
            return 30;
        case 'V':
            return 31;
        case 'W':
            return 32;
        case 'X':
            return 33;
        case 'Y':
            return 34;
        case 'Z':
            return 35;
        default:
            return 0;
    }
}

//Фкнкция переводит строку в целочисленное число
int StrToInt(const string &str)
{
    int result = 0;
    for (unsigned int i = 0; i < str.length(); ++i)
    {
        result = result * 10 + CharToInt(str[i]);
    }
    return result;
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

    srcNotation = StrToInt(srcNotationStr);
    dstNotation = StrToInt(dstNotationStr);

    if (!IsValidValue(valueStr, srcNotation))
    {
        cout << "Error: value is invalid. Possible symbols: ";
        PrintPossibleRadixSymbols(srcNotation);
        cout << "\n";
        return 1;
    }

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