#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

const unsigned ARG_COUNT = 2;

//Проверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
	return (argc == ARG_COUNT);
}

//Проверка существования файла
bool IsFileExists(wifstream &file)
{
	return file.good();
}

//Проверка файла на пустоту
bool IsFileEmpty(wifstream &file)
{
	return file.peek() == wifstream::traits_type::eof();
}

//Проверка файла ввода на существование и наличие в нём символов;
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
	wstring str = L"Кот";
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
				wcout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";
				if (getline(wcin, answer))
				{
					if (answer == L"y" || answer == L"Y")
					{
						wofstream dictionaryFile(dictionaryFileName);
						SaveDictionaryToFile(dictionaryFile, dictionary);
						dictionaryFile.close();
						wcout << "Изменения сохранены. До свидания.\n";
					}
				}
			}
			break;
		}
		if (!TryToPrintWordFromDictionary(word, dictionary))
		{
			wcout << "Неизвестное слово “" << word << "”. Введите перевод или пустую строку для отказа.\n";
			if (getline(wcin, answer))
			{
				if (!answer.empty())
				{
					AddWordToDictionary(word, answer, dictionary);
					wcout << "Слово “" << word << "” сохранено в словаре как “" << answer << "”.\n";
				}
				else
				{
					wcout << "Слово “" << word << "” проигнорировано.\n";
				}
			}
		}
	}
	return 0;
}