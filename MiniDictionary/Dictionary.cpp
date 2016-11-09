#include "stdafx.h"

// Чтение слов из файла в словарь
void ReadDictionaryFromFile(std::wifstream &dictionaryFile, std::map<std::wstring, std::wstring> &dictionary)
{
	std::wstring line;
	while (std::getline(dictionaryFile, line))
	{
		unsigned i = 0;
		std::wstring firstWord;
		for (i; i < line.length() && line[i] != L':'; ++i)
		{
			firstWord += line[i];
		}

		std::wstring secondWord;
		for (++i; i < line.length(); ++i)
		{
			secondWord += line[i];
		}

		if (!firstWord.empty() && !secondWord.empty())
		{
			dictionary.insert(std::pair<std::wstring, std::wstring>(firstWord, secondWord));
		}
	}
}

// Сохранение словаря в файл
void SaveDictionaryToFile(std::wofstream &dictionaryFile, const std::map<std::wstring, std::wstring> &dictionary)
{
	for (auto word : dictionary)
	{
		dictionaryFile << word.first << ":" << word.second << "\n";
	}
}

// Добавление слова в словарь
void AddWordToDictionary(const std::wstring &firstWord, const std::wstring &secondWord, std::map<std::wstring, std::wstring> &dictionary)
{
	dictionary.insert(std::pair<std::wstring, std::wstring>(firstWord, secondWord));
}

bool TryToPrintWordFromDictionary(const std::wstring &word, std::map<std::wstring, std::wstring> &dictionary)
{
	bool result = false;
	std::wstring lowerCasedWord;
	lowerCasedWord.resize(word.length());
	std::transform(word.begin(), word.end(), lowerCasedWord.begin(), ::tolower);

	std::wstring lowerCasedFirstWord;
	std::wstring lowerCasedSecondWord;

	for (auto wordInDictionary : dictionary)
	{
		lowerCasedFirstWord.resize(wordInDictionary.first.length());
		lowerCasedSecondWord.resize(wordInDictionary.second.length());
		std::transform(wordInDictionary.first.begin(), wordInDictionary.first.end(), lowerCasedFirstWord.begin(), ::tolower);
		std::transform(wordInDictionary.second.begin(), wordInDictionary.second.end(), lowerCasedSecondWord.begin(), ::tolower);

		std::wcout << lowerCasedFirstWord << " " << lowerCasedWord << "\n";
		if (lowerCasedFirstWord == lowerCasedWord)
		{
			std::wcout << wordInDictionary.second;
			result = true;
			break;
		}
		if (lowerCasedSecondWord == lowerCasedWord)
		{
			std::wcout << wordInDictionary.first << ", ";
			result = true;
		}
	}
	if (result)
	{
		std::cout << "\n";
	}
	return result;
}