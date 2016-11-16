#pragma once
#include "stdafx.h"

void ReadDictionaryFromFile(std::wifstream &dictionaryFile, std::map<std::wstring, std::wstring> &dictionary);
void SaveDictionaryToFile(std::wofstream &dictionaryFile, const std::map<std::wstring, std::wstring> &dictionary);
void AddWordToDictionary(const std::wstring &firstWord, const std::wstring &secondWord, std::map<std::wstring, std::wstring> &dictionary);
bool FindWordInDictionary(const std::wstring &word,
                          const std::map<std::wstring,
                          std::wstring> &dictionary,
                          std::vector<std::wstring> &translates);
bool TryToPrintWordFromDictionary(const std::wstring &word, std::map<std::wstring, std::wstring> &dictionary);