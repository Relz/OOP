#include "stdafx.h"
#include "VerifyPoint.h"
#include "..\Shape\color.h"

BOOST_AUTO_TEST_SUITE(HexToRGB_function)

BOOST_AUTO_TEST_CASE(cant_convert_wrong_hex_string)
{
    BOOST_REQUIRE_THROW(HexToRGB(""), std::exception);
}

BOOST_AUTO_TEST_CASE(can_convert_valid_hex_string)
{
    BOOST_CHECK(HexToRGB("000000") == sf::Color(0, 0, 0));
    BOOST_CHECK(HexToRGB("FF0000") == sf::Color(255, 0, 0));
    BOOST_CHECK(HexToRGB("00FF00") == sf::Color(0, 255, 0));
    BOOST_CHECK(HexToRGB("0000FF") == sf::Color(0, 0, 255));
    BOOST_CHECK(HexToRGB("FFFFFF") == sf::Color(255, 255, 255));
}

BOOST_AUTO_TEST_SUITE_END()