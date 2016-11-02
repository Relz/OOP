#include "stdafx.h"

// Чтение слов из файла в словарь
void ReadDictionaryFromFile(std::ifstream &dictionaryFile, std::map<std::string, std::string> &dictionary)
{
	std::string line;
	while (std::getline(dictionaryFile, line))
	{
		unsigned i = 0;
		std::string firstWord = "";
		for (i; i < line.length() && line[i] != ':'; ++i)
		{
			firstWord += line[i];
		}

		std::string secondWord = "";
		for (++i; i < line.length(); ++i)
		{
			secondWord += line[i];
		}

		if (!firstWord.empty() && !secondWord.empty())
		{
			dictionary.insert(std::pair<std::string, std::string>(firstWord, secondWord));
		}
	}
}

// Сохранение словаря в файл
void SaveDictionaryToFile(std::ofstream &dictionaryFile, const std::map<std::string, std::string> &dictionary)
{
	for (auto word : dictionary)
	{
		dictionaryFile << word.first << ":" << word.second << "\n";
	}
}

// Добавление слова в словарь
void AddWordToDictionary(const std::string &firstWord, const std::string &secondWord, std::map<std::string, std::string> &dictionary)
{
	dictionary.insert(std::pair<std::string, std::string>(firstWord, secondWord));
}

bool TryToPrintWordFromDictionary(const std::string &word, std::map<std::string, std::string> &dictionary)
{
	bool result = false;
	std::string lowerCasedWord;
	lowerCasedWord.resize(word.length());
	std::transform(word.begin(), word.end(), lowerCasedWord.begin(), ::tolower);

	std::string lowerCasedFirstWord;
	std::string lowerCasedSecondWord;

	for (auto wordInDictionary : dictionary)
	{
		lowerCasedFirstWord.resize(wordInDictionary.first.length());
		lowerCasedSecondWord.resize(wordInDictionary.second.length());
		std::transform(wordInDictionary.first.begin(), wordInDictionary.first.end(), lowerCasedFirstWord.begin(), ::tolower);
		std::transform(wordInDictionary.second.begin(), wordInDictionary.second.end(), lowerCasedSecondWord.begin(), ::tolower);

		if (lowerCasedFirstWord == lowerCasedWord)
		{
			std::cout << wordInDictionary.second;
			result = true;
			break;
		}
		if (lowerCasedSecondWord == lowerCasedWord)
		{
			std::cout << wordInDictionary.first << ", ";
			result = true;
		}
	}
	if (result)
	{
		std::cout << "\n";
	}
	return result;
}