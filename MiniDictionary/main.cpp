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
bool IsFileExists(wifstream &file)
{
	return file.good();
}

//�������� ����� �� �������
bool IsFileEmpty(wifstream &file)
{
	return file.peek() == wifstream::traits_type::eof();
}

//�������� ����� ����� �� ������������� � ������� � �� ��������;
bool IsValidInputFile(const wstring &inputFileName, wifstream &inputFile)
{
	if (!IsFileExists(inputFile))
	{
		wcerr << "File \"" << inputFileName << "\" not exists" << "\n";
		return false;
	}
	if (IsFileEmpty(inputFile))
	{
		wcerr << "File \"" << inputFileName << "\" is empty" << "\n";
		return false;
	}
	return true;
}

int wmain(int argc, wchar_t * argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	wstring str = L"���";
	wcout << str << "\n";
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	wcout << str << "\n";
	return 0;

	if (!IsValidArgumentsCount(argc))
	{
		cout << "MiniDictionary.exe <dictionary file>" << "\n";
		return 1;
	}

	wstring dictionaryFileName = argv[1];
	wifstream dictionaryFile(dictionaryFileName);
	if (!IsValidInputFile(dictionaryFileName, dictionaryFile))
	{
		return 1;
	}

	map <wstring, wstring> dictionary;
	ReadDictionaryFromFile(dictionaryFile, dictionary);
	dictionaryFile.close();

	size_t initialDictionarySize = dictionary.size();

	wstring word;
	wstring answer;

	while (getline(wcin, word))
	{
		if (word.empty())
		{
			continue;
		}
		if (word == L"...")
		{
			if (initialDictionarySize != dictionary.size())
			{
				wcout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n";
				if (getline(wcin, answer))
				{
					if (answer == L"y" || answer == L"Y")
					{
						wofstream dictionaryFile(dictionaryFileName);
						SaveDictionaryToFile(dictionaryFile, dictionary);
						dictionaryFile.close();
						wcout << "��������� ���������. �� ��������.\n";
					}
				}
			}
			break;
		}
		if (!TryToPrintWordFromDictionary(word, dictionary))
		{
			wcout << "����������� ����� �" << word << "�. ������� ������� ��� ������ ������ ��� ������.\n";
			if (getline(wcin, answer))
			{
				if (!answer.empty())
				{
					AddWordToDictionary(word, answer, dictionary);
					wcout << "����� �" << word << "� ��������� � ������� ��� �" << answer << "�.\n";
				}
				else
				{
					wcout << "����� �" << word << "� ���������������.\n";
				}
			}
		}
	}
	return 0;
}