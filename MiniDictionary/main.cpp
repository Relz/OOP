#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

const unsigned ARG_COUNT = 2;

//ѕроверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
	return (argc == ARG_COUNT);
}

//ѕроверка существовани€ файла
bool IsFileExists(ifstream &file)
{
	return file.good();
}

//ѕроверка файла на пустоту
bool IsFileEmpty(ifstream &file)
{
	return file.peek() == ifstream::traits_type::eof();
}

//ѕроверка файла ввода на существование и наличие в нЄм символов;
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
				cout << "¬ словарь были внесены изменени€. ¬ведите Y или y дл€ сохранени€ перед выходом.\n";
				if (getline(cin, answer))
				{
					if (answer == "y" || answer == "Y")
					{
						ofstream dictionaryFile(dictionaryFileName);
						SaveDictionaryToFile(dictionaryFile, dictionary);
						dictionaryFile.close();
						cout << "»зменени€ сохранены. ƒо свидани€.\n";
					}
				}
			}
			break;
		}
		if (!TryToPrintWordFromDictionary(word, dictionary))
		{
			cout << "Ќеизвестное слово У" << word << "Ф. ¬ведите перевод или пустую строку дл€ отказа.\n";
			if (getline(cin, answer))
			{
				if (!answer.empty())
				{
					AddWordToDictionary(word, answer, dictionary);
					cout << "—лово У" << word << "Ф сохранено в словаре как У" << answer << "Ф.\n";
				}
				else
				{
					cout << "—лово У" << word << "Ф проигнорировано.\n";
				}
			}
		}
	}
	return 0;
}