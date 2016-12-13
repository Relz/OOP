#include "stdafx.h"
#include "..\HttpUrl\HttpUrl.h"

struct HttpUrlFixture
{
    CHttpUrl httpUrl;
    HttpUrlFixture()
        : httpUrl("http://google.com/index.php")
    {

    }
};

BOOST_FIXTURE_TEST_SUITE(CHttpUrl_class, HttpUrlFixture)

    BOOST_AUTO_TEST_CASE(can_get_url)
    {
        BOOST_CHECK_EQUAL(httpUrl.GetURL(), "http://google.com/index.php");
    }
    BOOST_AUTO_TEST_CASE(can_get_protocol)
    {
        BOOST_CHECK_EQUAL(httpUrl.GetProtocol(), HTTP);
    }
    BOOST_AUTO_TEST_CASE(can_get_domain)
    {
        BOOST_CHECK_EQUAL(httpUrl.GetDomain(), "google.com");
    }
    BOOST_AUTO_TEST_CASE(can_get_document)
    {
        BOOST_CHECK_EQUAL(httpUrl.GetDocument(), "/index.php");
    }
    BOOST_AUTO_TEST_CASE(can_get_port)
    {
        BOOST_CHECK_EQUAL(httpUrl.GetPort(), 80);
    }

BOOST_AUTO_TEST_SUITE_END()