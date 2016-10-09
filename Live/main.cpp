#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const unsigned ARG_COUNT_MIN = 2;
const unsigned ARG_COUNT_MAX = 3;

const unsigned MAP_WIDTH_MAX = 256;
const unsigned MAP_HEIGHT_MAX = 256;

const char WALL = '*';
const char LIFE = '#';

//Проверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
    return (argc >= ARG_COUNT_MIN && argc <= ARG_COUNT_MAX);
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
bool IsValidInputFile(char *inputFileName, ifstream &inputFile)
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

unsigned GetLineWidth(ifstream &inputFile)
{
    string lineStr = "";
    unsigned i = 0;
    getline(inputFile, lineStr);
    for (i = 0; i < lineStr.length(); ++i)
    {
        if (lineStr[i] != WALL)
        {
            break;
        }
    }
    return i;
}

void PrintMap(vector<vector<unsigned char>> &liveMap)
{
    for (unsigned i = 0; i < liveMap.size(); ++i)
    {
        for (unsigned j = 0; j < liveMap.at(0).size(); ++j)
        {
            cout << "[" << liveMap.at(i).at(j) << "] ";
        }
        cout << "\n";
    }
}

bool IsBottomBorder(const string &lineStr)
{
    for (unsigned i = 1; i < lineStr.length() - 1; ++i)
    {
        if (lineStr[i] != WALL)
        {
            return false;
        }
    }
    return true;
}

void ProcessLine(vector<vector<unsigned char>> &liveMap, const string &lineStr, unsigned currentLine)
{
    for (unsigned i = 1; i < lineStr.length() - 1; ++i)
    {
        if (lineStr[i] == LIFE)
        {
            liveMap.at(currentLine - 2).at(i - 1) = LIFE;
        }
    }
}

int main(int argc, char* argv[])
{
    if (!IsValidArgumentsCount(argc))
    {
        cout << argv[0] << " using: <input file> [<output file>]" << "\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!IsValidInputFile(argv[1], inputFile))
    {
        return 1;
    }

    ofstream outputFile;
    if (argc == ARG_COUNT_MAX)
    {
        outputFile.open(argv[2]);
        if (!outputFile.is_open())
        {
            cout << "Failed to open " << argv[2] << " for writing" << "\n";
            return 1;
        }
    }
    
    unsigned lineWidth = GetLineWidth(inputFile);
    if (lineWidth < 3)
    {
        cout << "Error: live map width = 0" << "\n";
        return 1;
    }
    if (lineWidth - 2 > MAP_WIDTH_MAX)
    {
        cout << "Error: maximum map width: " << MAP_WIDTH_MAX << "\n";
        return 1;
    }
    unsigned liveMapWidth = lineWidth - 2;

    vector<vector<unsigned char>> liveMap(0);
    string lineStr = "";
    unsigned currentLine = 2;
    bool bottomBorderFound = false;
    bool wasError = false;

    while (getline(inputFile, lineStr))
    {
        if (lineStr.length() != lineWidth)
        {
            cout << "Error in line " << currentLine << ": line width does not match required (" << lineWidth << ")" << "\n";
            wasError = true;
            break;
        }
        if (lineStr[0] != WALL)
        {
            cout << "Error in line " << currentLine << ": left border expected" << "\n";
            wasError = true;
            break;
        }
        if (lineStr[lineWidth - 1] != WALL || lineWidth < 2)
        {
            cout << "Error in line " << currentLine << ": right border expected" << "\n";
            wasError = true;
            break;
        }
        if (IsBottomBorder(lineStr))
        {
            bottomBorderFound = true;
            break;
        }
        if (currentLine - 1 > MAP_HEIGHT_MAX)
        {
            cout << "Error: maximum map height: " << MAP_HEIGHT_MAX << "\n";
            wasError = true;
            break;
        }
        liveMap.resize(currentLine - 1);
        liveMap.at(currentLine - 2).resize(liveMapWidth);
        ProcessLine(liveMap, lineStr, currentLine);
        currentLine++;
    }

    if (!bottomBorderFound && !wasError)
    {
        cout << "Error in line " << currentLine << ": bottom border expected" << "\n";
        wasError = true;
    }

    inputFile.close();

    if (!wasError)
    {
        PrintMap(liveMap);
    }

    if (argc == ARG_COUNT_MAX)
    {
        outputFile.close();
    }

    return 0;
}