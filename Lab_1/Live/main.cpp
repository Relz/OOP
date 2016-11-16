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
const char LIFELESS = ' ';

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

void PrintMap(vector<vector<unsigned char>> &liveMap, ostream &outStream)
{
    for (unsigned i = 0; i <= liveMap.at(0).size(); ++i)
    {
        outStream << WALL;
    }
    outStream << WALL << "\n" << WALL;
    for (unsigned i = 0; i < liveMap.size(); ++i)
    {
        for (unsigned j = 0; j < liveMap.at(0).size(); ++j)
        {
            outStream << liveMap.at(i).at(j);
        }
        outStream << WALL << "\n" << WALL;
    }
    for (unsigned i = 0; i <= liveMap.at(0).size(); ++i)
    {
        outStream << WALL;
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

unsigned GetLifesCountAround(const vector<vector<unsigned char>> &liveMap, unsigned line, unsigned column)
{
    unsigned result = 0;
    for (unsigned i = line - 1; i < line + 2; ++i)
    {
        for (unsigned j = column - 1; j < column + 2; ++j)
        {
            if ((i != line || j != column) && i >= 0 && i < liveMap.size() && j >= 0 && j < liveMap.at(0).size() && liveMap.at(i).at(j) == LIFE)
            {
                result++;
            }
        }
    }
    return result;
}

vector<vector<unsigned char>> NextGeneration(const vector<vector<unsigned char>> &liveMap)
{
    vector<vector<unsigned char>> result(liveMap);
    for (unsigned i = 0; i < result.size(); ++i)
    {
        for (unsigned j = 0; j < result.at(0).size(); ++j)
        {
            if (liveMap.at(i).at(j) == LIFELESS)
            {
                if (GetLifesCountAround(liveMap, i, j) == 3)
                {
                    result.at(i).at(j) = LIFE;
                }
            }
            else if (liveMap.at(i).at(j) == LIFE)
            {
                unsigned lifesCountAround = GetLifesCountAround(liveMap, i, j);
                if (lifesCountAround < 2 || lifesCountAround > 3)
                {
                    result.at(i).at(j) = LIFELESS;
                }
            }
        }
    }
    return result;
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
        fill(liveMap.at(currentLine - 2).begin(), liveMap.at(currentLine - 2).end(), LIFELESS);
        ProcessLine(liveMap, lineStr, currentLine);
        currentLine++;
    }


    if (!bottomBorderFound && !wasError)
    {
        cout << "Error in line " << currentLine << ": bottom border expected" << "\n";
        wasError = true;
    }

    if (liveMap.size() == 0 && !wasError)
    {
        cout << "Error: live map height = 0" << "\n";
        wasError = true;
    }

    if (!wasError)
    {
        vector<vector<unsigned char>> nextLiveMap = NextGeneration(liveMap);
        if (argc == ARG_COUNT_MAX)
        {
            PrintMap(nextLiveMap, outputFile);
        }
        else
        {
            PrintMap(nextLiveMap, cout);
        }
    }

    inputFile.close();
    if (argc == ARG_COUNT_MAX)
    {
        outputFile.close();
    }

    return (wasError) ? 1 : 0;
}