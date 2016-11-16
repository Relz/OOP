#include "stdafx.h"
#include "..\MiniDictionary\Dictionary.h"

// Проверка наличия слова с переводом в словаре
bool IsWordExistsInDictionary(wstring const& word, wstring const& requiredTranslate, map<wstring, wstring> const& dictionary)
{
    vector<wstring> translates;
    if (FindWordInDictionary(word, dictionary, translates))
    {
        return (translates[0] == requiredTranslate);
    }
    return false;
}

// Функция ReadDictionaryFromFile
BOOST_AUTO_TEST_SUITE(FindWordInDictionary_function)

    // Находит в словаре значение по ключу
    BOOST_AUTO_TEST_CASE(return_value_by_key_in_dictionary)
    {
        map<wstring, wstring> dictionary = { { L"кот", L"cat" },{ L"яблоко", L"apple" } };
        BOOST_CHECK(IsWordExistsInDictionary(L"кот", L"cat", dictionary));
        BOOST_CHECK(IsWordExistsInDictionary(L"яблоко", L"apple", dictionary));
    }
    // Находит в словаре ключ по значению
    BOOST_AUTO_TEST_CASE(return_key_by_value_in_dictionary)
    {
        map<wstring, wstring> dictionary = { { L"кот", L"cat" },{ L"яблоко", L"apple" } };
        BOOST_CHECK(IsWordExistsInDictionary(L"cat", L"кот", dictionary));
        BOOST_CHECK(IsWordExistsInDictionary(L"apple", L"яблоко", dictionary));
    }

BOOST_AUTO_TEST_SUITE_END()

// Функция ReadDictionaryFromFile
BOOST_AUTO_TEST_SUITE(ReadDictionaryFromFile_function)

    // Создает пустой словарь при чтении пустого файла
    BOOST_AUTO_TEST_CASE(makes_empty_dictionary_from_empty_file)
    {
        wifstream dictionaryFile("empty_dictionary.txt");
        map<wstring, wstring> dictionary;
        ReadDictionaryFromFile(dictionaryFile, dictionary);
        BOOST_CHECK_EQUAL(dictionary.size(), 0);
    }

    // Читает 2 слова(кот, яблоко) с их переводами(cat, apple) из файла в словарь
    BOOST_AUTO_TEST_CASE(read_two_words_with_translates_from_file_to_dictionary)
    {
        wifstream dictionaryFile(L"dictionary_for_read_testing.txt");
        map<wstring, wstring> dictionary;
        ReadDictionaryFromFile(dictionaryFile, dictionary);
        BOOST_CHECK_EQUAL(dictionary.size(), 2);
        BOOST_CHECK(IsWordExistsInDictionary(L"кот", L"cat", dictionary));
        BOOST_CHECK(IsWordExistsInDictionary(L"яблоко", L"apple", dictionary));
    }

BOOST_AUTO_TEST_SUITE_END()

// Функция AddWordToDictionary
BOOST_AUTO_TEST_SUITE(AddWordToDictionary_function)

    // Добавляет слово с переводом в словарь
    BOOST_AUTO_TEST_CASE(adds_word_with_translation_to_dictionary)
    {
        map<wstring, wstring> dictionary;
        AddWordToDictionary(L"туман", L"fog", dictionary);
        BOOST_CHECK_EQUAL(dictionary.size(), 1);
        BOOST_CHECK(IsWordExistsInDictionary(L"туман", L"fog", dictionary));
    }

BOOST_AUTO_TEST_SUITE_END()

// Функция SaveDictionaryToFile
BOOST_AUTO_TEST_SUITE(SaveDictionaryToFile_function)

    // Сохраняет словарь в файл
    BOOST_AUTO_TEST_CASE(save_dictionary_to_file)
    {
        wofstream dictionaryFileOut(L"dictionary_for_write_testing.txt");
        map<wstring, wstring> dictionary = { {L"яблоко", L"apple"}, {L"кот", L"cat"} };
        SaveDictionaryToFile(dictionaryFileOut, dictionary);
        wifstream dictionaryFileIn("dictionary_for_write_testring.txt");
        ReadDictionaryFromFile(dictionaryFileIn, dictionary);
        BOOST_CHECK_EQUAL(dictionary.size(), 2);
        BOOST_CHECK(IsWordExistsInDictionary(L"яблоко", L"apple", dictionary));
        BOOST_CHECK(IsWordExistsInDictionary(L"кот", L"cat", dictionary));
    }

BOOST_AUTO_TEST_SUITE_END()