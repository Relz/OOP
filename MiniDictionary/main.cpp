#include "stdafx.h"
#include "DictionaryProcessor.h"

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
	setlocale(LC_ALL, "rus");
	if (!IsValidArgumentsCount(argc))
	{
		cout << "MiniDictionary.exe <dictionary file>" << "\n";
		return 1;
	}

	ifstream dictionaryFile(argv[1]);
	if (!IsValidInputFile(argv[1], dictionaryFile))
	{
		return 1;
	}

	map <string, string> dictionary;
	ReadDictionaryFromFile(dictionaryFile, dictionary);

	string word;
	while (cin >> word)
	{
		if (word == "...")
		{
			cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n";
			string answer = "";
			if (cin >> answer)
			{
				if (answer == "y")
				{
					cout << "��������� ���������. �� ��������.\n";
				}
			}
			break;
		}
		if (dictionary.find(word) != dictionary.end())
		{
			cout << dictionary.at(word) << "\n";
		}
		else
		{
			cout << "����������� ����� �" << word << "�. ������� ������� ��� ������ ������ ��� ������.\n";
			string answer = "";
			if (cin >> answer)
			{
				if (!answer.empty())
				{
					string secondWord;
					if (cin >> secondWord)
					{
						dictionary.insert(pair<string, string>(word, secondWord));
						cout << "����� �" << word << "� ��������� � ������� ��� �" << secondWord << "�.\n";
					}
				}
				else
				{
					cout << "����� �" << word << "����������������.\n";
				}
			}
		}
	}
	return 0;
}