#include "stdafx.h"
#include "..\MiniDictionary\Dictionary.h"

// ������� ReadDictionaryFromFile
BOOST_AUTO_TEST_SUITE(ReadDictionaryFromFile_function)

// ������� ������ ������� ��� ������ ������� �����
BOOST_AUTO_TEST_CASE(makes_empty_dictionary_from_empty_file)
{
	ifstream dictionaryFile("empty_dictionary.txt");
	map<string, string> dictionary;
	ReadDictionaryFromFile(dictionaryFile, dictionary);
	BOOST_CHECK_EQUAL(dictionary.size(), 0);
}

// ������ 2 ����� � �� ���������� �� ����� � �������
BOOST_AUTO_TEST_CASE(read_two_words_with_translates_from_file_to_dictionary)
{
	ifstream dictionaryFile("dictionary.txt");
	map<string, string> dictionary;
	ReadDictionaryFromFile(dictionaryFile, dictionary);
	BOOST_CHECK_EQUAL(dictionary.size(), 2);
	BOOST_CHECK_EQUAL(dictionary.at("������"), "apple");
	BOOST_CHECK_EQUAL(dictionary.at("���"), "cat");
}

BOOST_AUTO_TEST_SUITE_END()

// ������� AddWordToDictionary
BOOST_AUTO_TEST_SUITE(AddWordToDictionary_function)

// ��������� ����� � ��������� � �������
BOOST_AUTO_TEST_CASE(adds_word_with_translation_to_dictionary)
{
	map<string, string> dictionary;
	AddWordToDictionary("�����", "fog", dictionary);
	BOOST_CHECK_EQUAL(dictionary.size(), 1);
	BOOST_CHECK_EQUAL(dictionary.at("�����"), "fog");
}

BOOST_AUTO_TEST_SUITE_END()

// ������� SaveDictionaryToFile
BOOST_AUTO_TEST_SUITE(SaveDictionaryToFile_function)

// ��������� ������� � ����
BOOST_AUTO_TEST_CASE(save_dictionary_to_file)
{
	ofstream dictionaryFileOut("dictionary.txt");
	map<string, string> dictionary = { make_pair("������", "apple"), make_pair("���", "cat") };
	SaveDictionaryToFile(dictionaryFileOut, dictionary);
	ifstream dictionaryFileIn("dictionary.txt");
	ReadDictionaryFromFile(dictionaryFileIn, dictionary);
	BOOST_CHECK_EQUAL(dictionary.size(), 2);
	BOOST_CHECK_EQUAL(dictionary.at("������"), "apple");
	BOOST_CHECK_EQUAL(dictionary.at("���"), "cat");
}

BOOST_AUTO_TEST_SUITE_END()