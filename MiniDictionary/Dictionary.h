#pragma once
#include "stdafx.h"

void ReadDictionaryFromFile(std::wifstream &dictionaryFile, std::map<std::wstring, std::wstring> &dictionary);
void SaveDictionaryToFile(std::wofstream &dictionaryFile, const std::map<std::wstring, std::wstring> &dictionary);
void AddWordToDictionary(const std::wstring &firstWord, const std::wstring &secondWord, std::map<std::wstring, std::wstring> &dictionary);
bool TryToPrintWordFromDictionary(const std::wstring &word, std::map<std::wstring, std::wstring> &dictionary);