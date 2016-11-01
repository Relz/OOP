#include "stdafx.h"
#include "..\StlVector\vector.h"
#include <math.h>

using namespace std;

bool VectorsAreEquals(const vector<double> &vector0, const vector<double> &vector1)
{
	if (vector0.size() != vector1.size())
	{
		return false;
	}
	for (unsigned i = 0; i < vector0.size(); ++i)
	{
		if (fabs(vector0[i] - vector1[i]) > 0.00001 * fabs(vector0[i]))
		{
			return false;
		}
	}
	return true;
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
	BOOST_CHECK(VectorsAreEquals(numbers, copy));
}

// не изменяет содержимое вектора, который содержит отрицательные числа на нечетных позициях и 0 на четных позициях
BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_negative_evens_numbers_and_zero_odds_numbers)
{
	vector<double> numbers = { -1, 0, -3, 0 };
	vector<double> copy(numbers);
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEquals(numbers, copy));
}

// элементы, стоящие на четных позициях массива умножить на 2, 
// а из элементов, стоящих на нечетных позициях, вычесть сумму всех неотрицательных элементов
BOOST_AUTO_TEST_CASE(odds_mul_by_2_and_evens_sub_positive_numbers_sum)
{
	vector<double> numbers = { 1, 2.5, 3, 4.7, 5, 6.9, 7, 8.2, 9, 0 };
	vector<double> numbersRequired = { -46.3, 5, -44.3, 9.4, -42.3, 13.8, -40.3, 16.4, -38.3, 0 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEquals(numbers, numbersRequired));
	numbers = { -1, -53.21, 1, 24.112, -213.521, 9842.124 };
	numbersRequired = { -9868.236, -106.42, -9866.236, 48.224, -10080.757, 19684.248 };
	ProcessVector(numbers);
	BOOST_CHECK(VectorsAreEquals(numbers, numbersRequired));
}

BOOST_AUTO_TEST_SUITE_END()