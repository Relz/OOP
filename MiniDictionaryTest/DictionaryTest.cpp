#include "stdafx.h"
#include "..\MiniDictionary\Dictionary.h"

// ‘ункци€ ReadDictionaryFromFile
BOOST_AUTO_TEST_SUITE(ReadDictionaryFromFile_function)

// —оздает пустой словарь при чтении пустого файла
BOOST_AUTO_TEST_CASE(makes_empty_dictionary_from_empty_file)
{
	ifstream dictionaryFile("empty_dictionary.txt");
	map<string, string> dictionary;
	ReadDictionaryFromFile(dictionaryFile, dictionary);
	BOOST_CHECK_EQUAL(dictionary.size(), 0);
}

// „итает 2 слова с их переводами из файла в словарь
BOOST_AUTO_TEST_CASE(read_two_words_with_translates_from_file_to_dictionary)
{
	ifstream dictionaryFile("dictionary.txt");
	map<string, string> dictionary;
	ReadDictionaryFromFile(dictionaryFile, dictionary);
	BOOST_CHECK_EQUAL(dictionary.size(), 2);
	BOOST_CHECK_EQUAL(dictionary.at("€блоко"), "apple");
	BOOST_CHECK_EQUAL(dictionary.at("кот"), "cat");
}

BOOST_AUTO_TEST_SUITE_END()

// ‘ункци€ AddWordToDictionary
BOOST_AUTO_TEST_SUITE(AddWordToDictionary_function)

// ƒобавл€ет слово с переводом в словарь
BOOST_AUTO_TEST_CASE(adds_word_with_translation_to_dictionary)
{
	map<string, string> dictionary;
	AddWordToDictionary("туман", "fog", dictionary);
	BOOST_CHECK_EQUAL(dictionary.size(), 1);
	BOOST_CHECK_EQUAL(dictionary.at("туман"), "fog");
}

BOOST_AUTO_TEST_SUITE_END()

// ‘ункци€ SaveDictionaryToFile
BOOST_AUTO_TEST_SUITE(SaveDictionaryToFile_function)

// —охран€ет словарь в файл
BOOST_AUTO_TEST_CASE(save_dictionary_to_file)
{
	ofstream dictionaryFileOut("dictionary.txt");
	map<string, string> dictionary = { make_pair("€блоко", "apple"), make_pair("кот", "cat") };
	SaveDictionaryToFile(dictionaryFileOut, dictionary);
	ifstream dictionaryFileIn("dictionary.txt");
	ReadDictionaryFromFile(dictionaryFileIn, dictionary);
	BOOST_CHECK_EQUAL(dictionary.size(), 2);
	BOOST_CHECK_EQUAL(dictionary.at("€блоко"), "apple");
	BOOST_CHECK_EQUAL(dictionary.at("кот"), "cat");
}

BOOST_AUTO_TEST_SUITE_END()