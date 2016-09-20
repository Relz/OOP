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
bool IsValidRadix(unsigned int radix)
{
    return (radix >= MIN_NOTATION && radix <= MAX_NOTATION);
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

//Функция переводит цифру в символ
char DigitToChar(char ch)
{
    switch (ch)
    {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
        case 16:
            return 'G';
        case 17:
            return 'H';
        case 18:
            return 'I';
        case 19:
            return 'J';
        case 20:
            return 'K';
        case 21:
            return 'L';
        case 22:
            return 'M';
        case 23:
            return 'N';
        case 24:
            return 'O';
        case 25:
            return 'P';
        case 26:
            return 'Q';
        case 27:
            return 'R';
        case 28:
            return 'S';
        case 29:
            return 'T';
        case 30:
            return 'U';
        case 31:
            return 'V';
        case 32:
            return 'W';
        case 33:
            return 'X';
        case 34:
            return 'Y';
        case 35:
            return 'Z';
        default:
            return '0';
    }
}

//Ставит указанный массив задом-наперед
void ReverseString(string &str)
{
    char tmpCh = '0';
    for (unsigned int i = 0; i < (unsigned int)(str.length() / 2); ++i)
    {
        tmpCh = str[i];
        str[i] = str[str.length() - i - 1];
        str[str.length() - i - 1] = tmpCh;
    }
}

//Перевод числа в строку
string IntToStr(int number)
{
    string result;
    while (number != 0)
    {
        result += DigitToChar(number % 10);
        number /= 10;
    }
    ReverseString(result);
    return result;
}

//Функция переводит строку из системы счисления, задаваемой параметром radix, в десятичную
int ConvertToDec(const string &str, unsigned int radix)
{
    int result = 0;
    for (unsigned int i = 0; i < str.length(); ++i)
    {
        result += CharToInt(str[i]) * pow(radix, str.length() - i - 1);
    }
    return result;
}

//Функция переводит число в строке из десятичной системы счисления в указанную параметром radix
string ConvertFromTo(const string &numStr, unsigned int srcRadix, unsigned int dstRadix)
{
    string result;
    int decNum = ConvertToDec(numStr, srcRadix);
    if (decNum == 0)
    {
        result = "0";
    }
    while (decNum != 0)
    {
        result += DigitToChar(decNum % dstRadix);
        decNum /= dstRadix;
    }
    ReverseString(result);
    return result;
}

int main(int argc, char* argv[])
{
    if (!IsValidArgumentsCount(argc))
    {
        cout << "radix.exe <source radix> <destination radix> <value>" << "\n";
        return 1;
    }

    string srcRadixStr = argv[1];
    if (srcRadixStr == "")
    {
        cout << "Error: source radix not specified" << "\n";
        return 1;
    }

    string dstRadixStr = argv[2];
    if (dstRadixStr == "")
    {
        cout << "Error: destination radix not specified" << "\n";
        return 1;
    }

    string valueStr = argv[3];
    if (valueStr == "")
    {
        cout << "Error: value not specified" << "\n";
        return 1;
    }

    unsigned int srcRadix, dstRadix;

    srcRadix = StrToInt(srcRadixStr);
    dstRadix = StrToInt(dstRadixStr);

    if (!IsValidValue(valueStr, srcRadix))
    {
        cout << "Error: value is invalid. Possible symbols: ";
        PrintPossibleRadixSymbols(srcRadix);
        cout << "\n";
        return 1;
    }

    if (!IsValidRadix(srcRadix))
    {
        cout << "Error: invalid source radix. Supported values: " << MIN_NOTATION << ".." << MAX_NOTATION << "\n";
        return 1;
    }

    if (!IsValidRadix(dstRadix))
    {
        cout << "Error: invalid destination radix. Supported values: " << MIN_NOTATION << ".." << MAX_NOTATION << "\n";
        return 1;
    }

    cout << valueStr << "(" << srcRadix << ")" << " => " << ConvertFromTo(valueStr, srcRadix, dstRadix) << "(" << dstRadix << ")" << "\n";
}