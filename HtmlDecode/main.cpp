#include "stdafx.h"
#include "htmlDecodeProcessor.h"

using namespace std;

const unsigned ARG_COUNT = 2;

//�������� ������������� ���������� ������� ���������
bool IsValidArgumentsCount(int argc)
{
	return (argc == ARG_COUNT);
}

//�������� ������������� �����
bool IsFileExists(ifstream &file)
{
	return file.good();
}

//�������� ����� �� �������
bool IsFileEmpty(ifstream &file)
{
	return file.peek() == ifstream::traits_type::eof();
}

//�������� ����� ����� �� ������������� � ������� � �� ��������;
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