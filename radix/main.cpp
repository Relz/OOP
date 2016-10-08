#include <iostream>
#include <string>

using namespace std;

const unsigned argCount = 4;

const unsigned MIN_NOTATION = 2;
const unsigned MAX_NOTATION = 36;

const string & DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

//Проверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
    return (argc == argCount);
}

//Проверка системы счисления на диапазон от 2 до 36
bool IsValidRadix(unsigned radix)
{
    return (radix >= MIN_NOTATION && radix <= MAX_NOTATION);
}

//Проверка введенного числа на допустимые символы для указанной системы счисления
bool IsValidValue(const string &value, unsigned radix)
{
    bool found = false;
    if (value.length() > 0 && value[0] == '-')
    {
        found = true;
    }
    for (unsigned i = 0; i < value.length(); ++i)
    {
        if (value[i] >= DIGITS[0] && value[i] <= DIGITS[radix - 1])
        {
            found = true;
        }
        if (!found)
        {
            return false;
        }
        found = false;
    }
    return true;
}

//Вывод в консоль допустимых символов через запятую для указанной системы счисления
void PrintPossibleRadixSymbols(unsigned radix)
{
    for (unsigned i = 0; i < radix; ++i)
    {
        cout << DIGITS[i];
        if (i != radix - 1)
        {
            cout << ", ";
        }
    }
}

//Функция переводит символ в цифру
int CharToDigit(char ch)
{
    int digit = -1;
    if (ch >= '0' && ch <= '9')
    {
        digit = ch - '0';
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        digit = ch - 'A' + 10;
    }
    return digit;
}

//Функция переводит строку в целочисленное число
int StrToInt(const string &str, bool &wasError)
{
    int result = 0;
    for (unsigned i = 0; i < str.length(); ++i)
    {
        if (result > INT_MAX / 10)
        {
            wasError = true;
            return 0;
        }
        result = result * 10 + CharToDigit(str[i]);
    }
    return result;
}

//Функция переводит цифру в символ
char DigitToChar(unsigned digit)
{
    char ch = '0';
    if (digit >= 0 && digit <= 9)
    {
        ch = digit + '0';
    }
    else if (digit >= 10 && digit <= 35)
    {
        ch = digit + 'A' - 10;
    }
    return ch;
}

//Ставит указанный массив задом-наперед
void ReverseString(string &str)
{
    char tmpCh = '0';
    for (unsigned i = 0; i < (unsigned)(str.length() / 2); ++i)
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
int ConvertToDec(const string &str, unsigned radix, bool &isNegative, bool &wasError)
{
    int result = 0;
    int poweredNum = 0;
    for (unsigned i = 0; i < str.length(); ++i)
    {
        if (i == 0)
        {
            if (str[0] == '-')
            {
                isNegative = true;
                i++;
            }
            else
            {
                isNegative = false;
            }
        }
        poweredNum = (int)pow(radix, str.length() - i - 1);
        if (poweredNum == HUGE_VAL || CharToDigit(str[i]) == -1 || (CharToDigit(str[i]) != 0 && poweredNum > INT_MAX / CharToDigit(str[i])) || CharToDigit(str[i]) * poweredNum > INT_MAX - result)
        {
            wasError = true;
            break;
        }
        result += CharToDigit(str[i]) * poweredNum;
    }
    return result;
}

//Функция переводит число в строке из указанной системы счисления srcRadix в указанную параметром dstRadix
string ConvertFromTo(const string &numStr, unsigned srcRadix, unsigned dstRadix, bool &wasError)
{
    string result;
    bool isNegative;
    int decNum = ConvertToDec(numStr, srcRadix, isNegative, wasError);
    while (decNum != 0 && !wasError)
    {
        result += DigitToChar(decNum % dstRadix);
        decNum /= dstRadix;
    }
    if (isNegative)
    {
        result += '-';
    }
    ReverseString(result);
    return result;
}

int main(int argc, char* argv[])
{
    if (!IsValidArgumentsCount(argc))
    {
        cout << "Usage: radix.exe <source notation> <destination notation> <value>" << "\n";
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

    unsigned srcRadix, dstRadix;
    bool wasError = false;

    srcRadix = StrToInt(srcRadixStr, wasError);
    if (wasError)
    {
        cout << "Error: overflow, maximum source notation: " << INT_MAX << "\n";
        return 1;
    }

    dstRadix = StrToInt(dstRadixStr, wasError);
    if (wasError)
    {
        cout << "Error: overflow, maximum destination notation: " << INT_MAX << "\n";
        return 1;
    }

    if (!IsValidRadix(srcRadix))
    {
        cout << "Error: invalid source notation. Supported values: " << MIN_NOTATION << ".." << MAX_NOTATION << "\n";
        return 1;
    }

    if (!IsValidRadix(dstRadix))
    {
        cout << "Error: invalid destination notation. Supported values: " << MIN_NOTATION << ".." << MAX_NOTATION << "\n";
        return 1;
    }

    if (!IsValidValue(valueStr, srcRadix))
    {
        cout << "Error: value is invalid. Possible symbols: ";
        PrintPossibleRadixSymbols(srcRadix);
        cout << "\n";
        return 1;
    }

    string convertedNumStr = ConvertFromTo(valueStr, srcRadix, dstRadix, wasError);
    if (!wasError)
    {
        cout << valueStr << "(" << srcRadix << ")" << " => " << convertedNumStr << "(" << dstRadix << ")" << "\n";
    }
    else
    {
        cout << "Error: overflow, maximum value(in the decimal notation) = " << INT_MAX << "\n";
        return 1;
    }
    return 0;
}