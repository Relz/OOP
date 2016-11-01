#include "stdafx.h"
#include "..\HtmlDecode\HtmlDecodeProcessor.h"

using namespace std;

// Функция HtmlDecode
BOOST_AUTO_TEST_SUITE(HtmlDecode_function)

// При пустой строке возвращает пустую строку
BOOST_AUTO_TEST_CASE(returns_empty_string_if_input_empty_string)
{
	BOOST_CHECK_EQUAL(HtmlDecode(""), "");
}

// Если строка не содержит HTML-сущеностей, то функция вернет исходную строку
BOOST_AUTO_TEST_CASE(returns_source_string_if_it_does_not_have_html_entities)
{
	string strWithoutHtmlEntities = "Cat says: \"meow\"";
	BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlEntities), strWithoutHtmlEntities);
}

// Если строка содержит незавершенные HTML-сущености, то функция оставит их без изменения
BOOST_AUTO_TEST_CASE(returns_source_string_if_html_entities_are_wrong)
{
	string strWithoutHtmlEntities = "Cat &ltsays&gt &quotMeow&quot. M&ampM&aposs";
	BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlEntities), strWithoutHtmlEntities);
}

// Программа не завершается с ошибкой, если строка содержит незавершенную HTML-сущеность, проверка которой приводит алгоритм к концу строки
BOOST_AUTO_TEST_CASE(program_does_not_crash_if_input_string_has_wrong_html_entity_at_end_of_line)
{
	string strWithoutHtmlEntities = "&apo";
	BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlEntities), strWithoutHtmlEntities);
}

// Проверка строки с содержанием html-сущностей, стоящих друг за другом
BOOST_AUTO_TEST_CASE(program_works_correctly_with_html_entities_without_another_words)
{
	string strWithoutHtmlEntities = "&lt;&gt;&quot;&quot;&amp;&apos;";
	BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlEntities), "<>\"\"&’");
}

// Проверка строки с содержанием завершенных и незавершенных html-сущностей, стоящих друг за другом
BOOST_AUTO_TEST_CASE(program_works_correctly_with_wrong_and_right_html_entities_without_another_words)
{
	string strWithoutHtmlEntities = "&lt&gt;&quot;&quot&amp;&apos;";
	BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlEntities), "&lt>\"&quot&’");
}

// Проверка строки с содержанием html-сущностей
BOOST_AUTO_TEST_CASE(program_works_correctly_with_html_entities)
{
	string str = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	BOOST_CHECK_EQUAL(HtmlDecode(str), "Cat <says> \"Meow\". M&M’s");
}



BOOST_AUTO_TEST_SUITE_END()