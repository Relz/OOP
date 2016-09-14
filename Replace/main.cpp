#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Проверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
    return (argc == 5);
}

//Проверка существования файла
bool IsFileExists(ifstream &file)
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
bool IsValidInputOutputFiles(char* argv[], ifstream &inputFile, ofstream &outputFile)
{
	if (!IsFileExists(inputFile))
	{
		cout << "File \"" << argv[1] << "\" not exists" << "\n";
		return false;
	}
	if (IsFileEmpty(inputFile))
	{
		cout << "File \"" << argv[1] << "\" is empty" << "\n";
		return false;
	}
	if (!outputFile.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing" << "\n";
		return false;
	}
	return true;
}

//Замена в файле ввода искомой строки и запись результата в файл вывода
void Replace(ifstream &inputFile, ofstream &outputFile, string const& search, string const& replace)
{
	string line;
	size_t pos = 0;
	unsigned int minPos = 0;
	bool isLineInProcessing = true;

	while (getline(inputFile, line))
	{
		minPos = 0;
		isLineInProcessing = true;

		while (isLineInProcessing)
		{
			pos = line.find(search, minPos);
			if (pos != string::npos)
			{
				line.replace(pos, search.size(), replace);
				minPos = pos + replace.size();
			}
			else
			{
				isLineInProcessing = false;
			}
		}
		outputFile << line << "\n";
	}
}

int main(int argc, char* argv[])
{
	if (!IsValidArgumentsCount(argc))
    {
        cout << "replace.exe using: <input file> <output file> <search string> <replace string>" << "\n";
        return 1;
	}

	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);
	if (!IsValidInputOutputFiles(argv, inputFile, outputFile))
	{
		return 1;
	}

	string search = argv[3];
	string replace = argv[4];
    if (search.size() == 0)
    {
        cout << "Search string isn't set" << "\n";
        return 1;
    }

	Replace(inputFile, outputFile, search, replace);

    return 0;
}