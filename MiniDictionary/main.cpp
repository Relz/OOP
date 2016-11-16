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
bool IsFileExists(wifstream &file)
{
    return file.good();
}

//ѕроверка файла на пустоту
bool IsFileEmpty(wifstream &file)
{
    return file.peek() == wifstream::traits_type::eof();
}

//ѕроверка файла ввода на существование и наличие в нЄм символов;
bool IsValidInputFile(const wstring &inputFileName, wifstream &inputFile)
{
    if (!IsFileExists(inputFile))
    {
        wcerr << L"File \"" << inputFileName << L"\" not exists" << L"\n";
        return false;
    }
    if (IsFileEmpty(inputFile))
    {
        wcerr << L"File \"" << inputFileName << L"\" is empty" << L"\n";
        return false;
    }
    return true;
}

int wmain(int argc, wchar_t * argv[])
{
    std::locale::global(std::locale("rus"));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (!IsValidArgumentsCount(argc))
    {
        wcout << L"MiniDictionary.exe <dictionary file>" << L"\n";
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
                wcout << L"¬ словарь были внесены изменени€. ¬ведите Y или y дл€ сохранени€ перед выходом.\n";
                if (getline(wcin, answer))
                {
                    if (answer == L"y" || answer == L"Y")
                    {
                        wofstream dictionaryFile(dictionaryFileName);
                        SaveDictionaryToFile(dictionaryFile, dictionary);
                        dictionaryFile.close();
                        wcout << L"»зменени€ сохранены. ƒо свидани€.\n";
                    }
                }
            }
            break;
        }
        if (!TryToPrintWordFromDictionary(word, dictionary))
        {
            wcout << L"Ќеизвестное слово У" << word << L"Ф. ¬ведите перевод или пустую строку дл€ отказа.\n";
            if (getline(wcin, answer))
            {
                if (!answer.empty())
                {
                    AddWordToDictionary(word, answer, dictionary);
                    wcout << L"—лово У" << word << L"Ф сохранено в словаре как У" << answer << L"Ф.\n";
                }
                else
                {
                    wcout << L"—лово У" << word << L"Ф проигнорировано.\n";
                }
            }
        }
    }
    return 0;
}