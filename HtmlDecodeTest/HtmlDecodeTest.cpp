#include "stdafx.h"
#include "..\HtmlDecode\HtmlDecode.h"

using namespace std;

// ������� HtmlDecode
BOOST_AUTO_TEST_SUITE(HtmlDecode_function)

    // ��� ������ ������ ���������� ������ ������
    BOOST_AUTO_TEST_CASE(returns_empty_string_if_input_empty_string)
    {
        BOOST_CHECK_EQUAL(HtmlDecode(""), "");
    }

    // ��������� ��� ��������� ������, �� ���������� HTML-���������
    BOOST_AUTO_TEST_CASE(returns_source_string_if_it_does_not_have_html_entities)
    {
        string strWithoutHtmlEntities = "Cat says: \"meow\"";
        BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlEntities), strWithoutHtmlEntities);
    }

    // ��������� ��� ��������� ������������� html-��������
    BOOST_AUTO_TEST_CASE(returns_source_string_if_html_entities_are_wrong)
    {
        string strWithoutHtmlEntities = "Cat &ltsays&gt &quotMeow&quot. M&ampM&aposs";
    BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlEntities), strWithoutHtmlEntities);
    }

    // �������� HTML-��������
    BOOST_AUTO_TEST_CASE(replace_entities)
    {
        string strWithHtmlEntities = "Cat &lt;says&gt; &quot;Meows. M&amp;M&apos;s";
        string requiredStr = "Cat <says> \"Meows. M&M�s";
        BOOST_CHECK_EQUAL(HtmlDecode(strWithHtmlEntities), requiredStr);

        strWithHtmlEntities = "Cat &lt;says&gt; &quot;&lt;Meow&gt;&quot;. M&amp;M&apos;s. &amp;Cat &lt;says&gt; &quot;Meow&quot;.";
        requiredStr = "Cat <says> \"<Meow>\". M&M�s. &Cat <says> \"Meow\".";
        BOOST_CHECK_EQUAL(HtmlDecode(strWithHtmlEntities), requiredStr);
    }

BOOST_AUTO_TEST_SUITE_END()