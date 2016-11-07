#include "stdafx.h"
#include "../PrimeNumbersSetGenerator/PrimeNumbers.h"
#include <iostream>

using namespace std;

// ������� ProcessVector
BOOST_AUTO_TEST_SUITE(GeneratePrimeNumbersSet_function)

// ������� ������ ��������� ������� �����, ���� ������� ������� �� ��������� ����������� ���������
BOOST_AUTO_TEST_CASE(makes_empty_prime_numbers_set_if_upper_bound_is_out_of_range)
{
	set<int> primeNumbers = GeneratePrimeNumbersSet(0);
	BOOST_CHECK(primeNumbers.empty());

	primeNumbers = GeneratePrimeNumbersSet(100000001);
	BOOST_CHECK(primeNumbers.empty());
}

// ������� ������ ��������� ������� �����, ���� ������� ������� ������������
BOOST_AUTO_TEST_CASE(makes_empty_prime_numbers_set_if_upper_bound_is_negative)
{
	set<int> primeNumbers = GeneratePrimeNumbersSet(-1);
	BOOST_CHECK(primeNumbers.empty());
}

// ������� ��������� ���� ������� �����, �� ����������� �������� ������� �������.
BOOST_AUTO_TEST_CASE(makes_prime_numbers_set_not_exceeding_upper_bound)
{
	set<int> primeNumbers = GeneratePrimeNumbersSet(7);
	BOOST_CHECK_EQUAL(primeNumbers.size(), 4);

	primeNumbers = GeneratePrimeNumbersSet(20);
	BOOST_CHECK_EQUAL(primeNumbers.size(), 8);

	primeNumbers = GeneratePrimeNumbersSet(100000000);
	BOOST_CHECK_EQUAL(primeNumbers.size(), 5761455);
}

BOOST_AUTO_TEST_SUITE_END()