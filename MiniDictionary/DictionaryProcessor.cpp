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
	if (dictionary.find(word) != dictionary.end())
	{
		std::cout << dictionary.at(word);
		result = true;
	}
	for (auto wordInDictionary : dictionary)
	{
		if (wordInDictionary.second == word)
		{
			std::cout << wordInDictionary.first << ", ";
			result = true;
		}
	}
	std::cout << "\n";
	return result;
}