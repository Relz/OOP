#include "stdafx.h"
#include "Dictionary.h"

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
bool IsValidInputFile(const string &inputFileName, ifstream &inputFile)
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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (!IsValidArgumentsCount(argc))
	{
		cout << "MiniDictionary.exe <dictionary file>" << "\n";
		return 1;
	}

	string dictionaryFileName = argv[1];
	ifstream dictionaryFile(dictionaryFileName);
	if (!IsValidInputFile(dictionaryFileName, dictionaryFile))
	{
		return 1;
	}

	map <string, string> dictionary;
	ReadDictionaryFromFile(dictionaryFile, dictionary);
	dictionaryFile.close();

	size_t initialDictionarySize = dictionary.size();

	string word;
	string answer;

	while (getline(cin, word))
	{
		if (word.empty())
		{
			continue;
		}
		if (word == "...")
		{
			if (initialDictionarySize != dictionary.size())
			{
				cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n";
				if (getline(cin, answer))
				{
					if (answer == "y" || answer == "Y")
					{
						ofstream dictionaryFile(dictionaryFileName);
						SaveDictionaryToFile(dictionaryFile, dictionary);
						dictionaryFile.close();
						cout << "��������� ���������. �� ��������.\n";
					}
				}
			}
			break;
		}
		if (!TryToPrintWordFromDictionary(word, dictionary))
		{
			cout << "����������� ����� �" << word << "�. ������� ������� ��� ������ ������ ��� ������.\n";
			if (getline(cin, answer))
			{
				if (!answer.empty())
				{
					AddWordToDictionary(word, answer, dictionary);
					cout << "����� �" << word << "� ��������� � ������� ��� �" << answer << "�.\n";
				}
				else
				{
					cout << "����� �" << word << "� ���������������.\n";
				}
			}
		}
	}
	return 0;
}