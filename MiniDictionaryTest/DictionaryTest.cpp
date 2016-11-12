#include "stdafx.h"
#include "..\MiniDictionary\Dictionary.h"

// �������� ������� ����� � ��������� � �������
bool IsWordExistsInDictionary(wstring const& word, wstring const& requiredTranslate, map<wstring, wstring> const& dictionary)
{
    vector<wstring> translates;
    if (FindWordInDictionary(word, dictionary, translates))
    {
        return (translates[0] == requiredTranslate);
    }
    return false;
}

// ������� ReadDictionaryFromFile
BOOST_AUTO_TEST_SUITE(FindWordInDictionary_function)

    // ������� � ������� �������� �� �����
    BOOST_AUTO_TEST_CASE(return_value_by_key_in_dictionary)
    {
        map<wstring, wstring> dictionary = { { L"���", L"cat" },{ L"������", L"apple" } };
        BOOST_CHECK(IsWordExistsInDictionary(L"���", L"cat", dictionary));
        BOOST_CHECK(IsWordExistsInDictionary(L"������", L"apple", dictionary));
    }
    // ������� � ������� ���� �� ��������
    BOOST_AUTO_TEST_CASE(return_key_by_value_in_dictionary)
    {
        map<wstring, wstring> dictionary = { { L"���", L"cat" },{ L"������", L"apple" } };
        BOOST_CHECK(IsWordExistsInDictionary(L"cat", L"���", dictionary));
        BOOST_CHECK(IsWordExistsInDictionary(L"apple", L"������", dictionary));
    }

BOOST_AUTO_TEST_SUITE_END()

// ������� ReadDictionaryFromFile
BOOST_AUTO_TEST_SUITE(ReadDictionaryFromFile_function)

    // ������� ������ ������� ��� ������ ������� �����
    BOOST_AUTO_TEST_CASE(makes_empty_dictionary_from_empty_file)
    {
        wifstream dictionaryFile("empty_dictionary.txt");
        map<wstring, wstring> dictionary;
        ReadDictionaryFromFile(dictionaryFile, dictionary);
        BOOST_CHECK_EQUAL(dictionary.size(), 0);
    }

    // ������ 2 �����(���, ������) � �� ����������(cat, apple) �� ����� � �������
    BOOST_AUTO_TEST_CASE(read_two_words_with_translates_from_file_to_dictionary)
    {
        wifstream dictionaryFile(L"dictionary_for_read_testing.txt");
        map<wstring, wstring> dictionary;
        ReadDictionaryFromFile(dictionaryFile, dictionary);
        BOOST_CHECK_EQUAL(dictionary.size(), 2);
        BOOST_CHECK(IsWordExistsInDictionary(L"���", L"cat", dictionary));
        BOOST_CHECK(IsWordExistsInDictionary(L"������", L"apple", dictionary));
    }

BOOST_AUTO_TEST_SUITE_END()

// ������� AddWordToDictionary
BOOST_AUTO_TEST_SUITE(AddWordToDictionary_function)

    // ��������� ����� � ��������� � �������
    BOOST_AUTO_TEST_CASE(adds_word_with_translation_to_dictionary)
    {
        map<wstring, wstring> dictionary;
        AddWordToDictionary(L"�����", L"fog", dictionary);
        BOOST_CHECK_EQUAL(dictionary.size(), 1);
        BOOST_CHECK(IsWordExistsInDictionary(L"�����", L"fog", dictionary));
    }

BOOST_AUTO_TEST_SUITE_END()

// ������� SaveDictionaryToFile
BOOST_AUTO_TEST_SUITE(SaveDictionaryToFile_function)

    // ��������� ������� � ����
    BOOST_AUTO_TEST_CASE(save_dictionary_to_file)
    {
        wofstream dictionaryFileOut(L"dictionary_for_write_testing.txt");
        map<wstring, wstring> dictionary = { {L"������", L"apple"}, {L"���", L"cat"} };
        SaveDictionaryToFile(dictionaryFileOut, dictionary);
        wifstream dictionaryFileIn("dictionary_for_write_testring.txt");
        ReadDictionaryFromFile(dictionaryFileIn, dictionary);
        BOOST_CHECK_EQUAL(dictionary.size(), 2);
        BOOST_CHECK(IsWordExistsInDictionary(L"������", L"apple", dictionary));
        BOOST_CHECK(IsWordExistsInDictionary(L"���", L"cat", dictionary));
    }

BOOST_AUTO_TEST_SUITE_END()