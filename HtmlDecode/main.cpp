#include "stdafx.h"
#include "htmlDecodeProcessor.h"

using namespace std;

const unsigned ARG_COUNT = 2;

//Проверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
	return (argc == ARG_COUNT);
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

//Проверка файла ввода на существование и наличие в нём символов;
bool IsValidInputFile(char* inputFileName, ifstream &inputFile)
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

int main(int argc, char * argv[])
{
	if (!IsValidArgumentsCount(argc))
	{
		cout << "HtmlDecode.exe <input file>" << "\n";
		return 1;
	}

	ifstream inputFile(argv[1]);
	if (!IsValidInputFile(argv[1], inputFile))
	{
		return 1;
	}

	string line;
	while (getline(inputFile, line))
	{
		cout << HtmlDecode(line);
	}
	return 0;
}