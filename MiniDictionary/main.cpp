#include "stdafx.h"
#include "DictionaryProcessor.h"

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
			cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";
			string answer = "";
			if (cin >> answer)
			{
				if (answer == "y")
				{
					cout << "Изменения сохранены. До свидания.\n";
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
			cout << "Неизвестное слово “" << word << "”. Введите перевод или пустую строку для отказа.\n";
			string answer = "";
			if (cin >> answer)
			{
				if (!answer.empty())
				{
					string secondWord;
					if (cin >> secondWord)
					{
						dictionary.insert(pair<string, string>(word, secondWord));
						cout << "Слово “" << word << "” сохранено в словаре как “" << secondWord << "”.\n";
					}
				}
				else
				{
					cout << "Слово “" << word << "”проигнорировано.\n";
				}
			}
		}
	}
	return 0;
}