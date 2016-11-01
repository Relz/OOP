#include "stdafx.h"
#include "..\HtmlDecode\HtmlDecodeProcessor.h"

using namespace std;

// ������� HtmlDecode
BOOST_AUTO_TEST_SUITE(HtmlDecode_function)

// ��� ������ ������ ���������� ������ ������
BOOST_AUTO_TEST_CASE(returns_empty_string_if_input_empty_string)
{
	BOOST_CHECK_EQUAL(HtmlDecode(""), "");
}

// ���� ������ �� �������� HTML-����������, �� ������� ������ �������� ������
BOOST_AUTO_TEST_CASE(returns_source_string_if_it_does_not_have_html_entities)
{
	string strWithoutHtmlEntities = "Cat says: \"meow\"";
	BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlEntities), strWithoutHtmlEntities);
}

// ���� ������ �������� ������������� HTML-���������, �� ������� ������� �� ��� ���������
BOOST_AUTO_TEST_CASE(returns_source_string_if_html_entities_are_wrong)
{
	string strWithoutHtmlEntities = "Cat &ltsays&gt &quotMeow&quot. M&ampM&aposs";
	BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlEntities), strWithoutHtmlEntities);
}

// ��������� �� ����������� � �������, ���� ������ �������� ������������� HTML-���������, �������� ������� �������� �������� � ����� ������
BOOST_AUTO_TEST_CASE(program_does_not_crash_if_input_string_has_wrong_html_entity_at_end_of_line)
{
	string strWithoutHtmlEntities = "&apo";
	BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlEntities), strWithoutHtmlEntities);
}

// �������� ������ � ����������� html-���������, ������� ���� �� ������
BOOST_AUTO_TEST_CASE(program_works_correctly_with_html_entities_without_another_words)
{
	string strWithoutHtmlEntities = "&lt;&gt;&quot;&quot;&amp;&apos;";
	BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlEntities), "<>\"\"&�");
}

// �������� ������ � ����������� ����������� � ������������� html-���������, ������� ���� �� ������
BOOST_AUTO_TEST_CASE(program_works_correctly_with_wrong_and_right_html_entities_without_another_words)
{
	string strWithoutHtmlEntities = "&lt&gt;&quot;&quot&amp;&apos;";
	BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlEntities), "&lt>\"&quot&�");
}

// �������� ������ � ����������� html-���������
BOOST_AUTO_TEST_CASE(program_works_correctly_with_html_entities)
{
	string str = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	BOOST_CHECK_EQUAL(HtmlDecode(str), "Cat <says> \"Meow\". M&M�s");
}



BOOST_AUTO_TEST_SUITE_END()