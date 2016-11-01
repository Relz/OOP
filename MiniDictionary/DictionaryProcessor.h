#pragma once
#include "stdafx.h"

void ReadDictionaryFromFile(std::ifstream &dictionaryFile, std::map<std::string, std::string> &dictionary);
void SaveDictionaryToFile(std::ofstream &dictionaryFile, const std::map<std::string, std::string> &dictionary);
void AddWordToDictionary(const std::string &firstWord, const std::string &secondWord, std::map<std::string, std::string> &dictionary);
bool TryToPrintWordFromDictionary(const std::string &word, std::map<std::string, std::string> &dictionary);