#include "stdafx.h"
#include "..\StlVector\vector.h"
#include <iostream>
#include <math.h>

using namespace std;

bool vectorsAreEquals(vector<double> vector0, vector<double> vector1)
{
	if (vector0.size() == vector1.size())
	{
		for (unsigned i = 0; i < vector0.size(); ++i)
		{
			if (fabs(vector0[i] - vector1[i]) > 0.00001 * fabs(vector0[i]))
			{
				std::cout << vector0[i] << " != " << vector1[i] << "\n";
				return false;
			}
		}
		return true;
	}
	return false;
}

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

// Создает пустой вектор из пустого вектора
BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
{
	vector<double> emptyVector;
	ProcessVector(emptyVector);
	BOOST_CHECK(emptyVector.empty());
}

// не изменяет содержимое вектора, который содержит только 0
BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_zero_numbers)
{
	vector<double> numbers = { 0, 0, 0 };
	vector<double> copy(numbers);
	ProcessVector(numbers);
	BOOST_CHECK(vectorsAreEquals(numbers, copy));
}

// не изменяет содержимое вектора, который содержит отрицательные числа на нечетных позициях и 0 на четных позициях
BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_negative_evens_numbers_and_zero_odds_numbers)
{
	vector<double> numbers = { -21.412, 0, -41.378 };
	vector<double> copy(numbers);
	ProcessVector(numbers);
	BOOST_CHECK(vectorsAreEquals(numbers, copy));
}

// вектор содержит только положительные числа
BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_positive_numbers)
{
	vector<double> numbers = { 1, 24.112, 9842.124 };
	vector<double> numbersRequired = { 1, 19782.7, 9842.12 };
	ProcessVector(numbers);
	BOOST_CHECK(vectorsAreEquals(numbers, numbersRequired));
}

// вектор содержит любые числа
BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_any_numbers)
{
	vector<double> numbers = { -1, -53.21, 1, 24.112, -213.521, 9842.124 };
	vector<double> numbersRequired = { -1, 19628.1, 1, 19782.7, -213.521, 39418.7 };
	ProcessVector(numbers);
	BOOST_CHECK(vectorsAreEquals(numbers, numbersRequired));
}

BOOST_AUTO_TEST_SUITE_END()