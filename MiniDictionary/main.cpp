#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

const unsigned ARG_COUNT = 2;

//�������� ������������� ���������� ������� ���������
bool IsValidArgumentsCount(int argc)
{
    return (argc == ARG_COUNT);
}

//�������� ������������� �����
bool IsFileExists(wifstream &file)
{
    return file.good();
}

//�������� ����� �� �������
bool IsFileEmpty(wifstream &file)
{
    return file.peek() == wifstream::traits_type::eof();
}

//�������� ����� ����� �� ������������� � ������� � �� ��������;
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
                wcout << L"� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n";
                if (getline(wcin, answer))
                {
                    if (answer == L"y" || answer == L"Y")
                    {
                        wofstream dictionaryFile(dictionaryFileName);
                        SaveDictionaryToFile(dictionaryFile, dictionary);
                        dictionaryFile.close();
                        wcout << L"��������� ���������. �� ��������.\n";
                    }
                }
            }
            break;
        }
        if (!TryToPrintWordFromDictionary(word, dictionary))
        {
            wcout << L"����������� ����� �" << word << L"�. ������� ������� ��� ������ ������ ��� ������.\n";
            if (getline(wcin, answer))
            {
                if (!answer.empty())
                {
                    AddWordToDictionary(word, answer, dictionary);
                    wcout << L"����� �" << word << L"� ��������� � ������� ��� �" << answer << L"�.\n";
                }
                else
                {
                    wcout << L"����� �" << word << L"� ���������������.\n";
                }
            }
        }
    }
    return 0;
}