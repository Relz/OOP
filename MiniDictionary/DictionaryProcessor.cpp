#include "stdafx.h"

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

		dictionary.insert(std::pair<std::string, std::string>(firstWord, secondWord));
	}
}