#include "stdafx.h"
#include "../PrimeNumbersSetGenerator/PrimeNumbers.h"
#include <iostream>

using namespace std;

// ������� ProcessVector
BOOST_AUTO_TEST_SUITE(GeneratePrimeNumbersSet_function)

    // ������� ������ ��������� ������� �����, ���� ������� ������� �� ��������� ����������� ���������
    BOOST_AUTO_TEST_CASE(makes_empty_prime_numbers_set_if_upper_bound_is_out_of_range)
    {
        BOOST_CHECK(GeneratePrimeNumbersSet(0).empty());
        BOOST_CHECK(GeneratePrimeNumbersSet(100000001).empty());
    }

    // ������� ������ ��������� ������� �����, ���� ������� ������� ����� �� ����������� ������� ������
    BOOST_AUTO_TEST_CASE(makes_empty_prime_numbers_set_if_upper_bound_less_than_min_prime_number)
    {
        BOOST_CHECK(GeneratePrimeNumbersSet(1).empty());
    }

    // ������� ��������� ������� �����, ���������� �� ������ �����, ���� ������� ������� ����� ������������ �������� �����
    BOOST_AUTO_TEST_CASE(makes_prime_numbers_set_consisting_one_number_if_upper_bound_equal_min_prime_number)
    {
        BOOST_CHECK_EQUAL(GeneratePrimeNumbersSet(2).size(), 1);
    }

    // ������� ���������� ��������� ������� �����, ���� ������� ������� ����� �������� ����� � ��������� �� ���
    BOOST_AUTO_TEST_CASE(makes_equal_prime_numbers_set_if_upper_bound_equal_prime_number_and_next_for_it)
    {
        BOOST_CHECK_EQUAL(GeneratePrimeNumbersSet(19).size(), 8);
        BOOST_CHECK_EQUAL(GeneratePrimeNumbersSet(20).size(), 8);
    }

    // ������� ������ ��������� ������� �����, ���� ������� ������� ������������
    BOOST_AUTO_TEST_CASE(makes_empty_prime_numbers_set_if_upper_bound_is_negative)
    {
        BOOST_CHECK(GeneratePrimeNumbersSet(-1).empty());
    }

    // ������� ��������� ���� ������� �����, �� ����������� �������� ������� �������.
    BOOST_AUTO_TEST_CASE(makes_prime_numbers_set_not_exceeding_upper_bound)
    {
        BOOST_CHECK_EQUAL(GeneratePrimeNumbersSet(7).size(), 4);
        BOOST_CHECK_EQUAL(GeneratePrimeNumbersSet(25).size(), 9);

    #ifdef NDEBUG
        BOOST_CHECK_EQUAL(GeneratePrimeNumbersSet(100000000).size(), 5761455);
    #endif
    }

BOOST_AUTO_TEST_SUITE_END()