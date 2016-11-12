#include "stdafx.h"
#include "..\StlVector\vector.h"
#include <math.h>
#include <iostream>

using namespace std;

bool VectorsAreEquals(const vector<double> &vector0, const vector<double> &vector1)
{
    if (vector0.size() != vector1.size())
    {
        return false;
    }
    for (size_t i = 0; i < vector0.size(); ++i)
    {
        if (fabs(vector0[i] - vector1[i]) > 0.00001 * fabs(vector0[i]))
        {
            return false;
        }
    }
    return true;
}

bool ProcessVectorEqual(vector<double> numbers, const vector<double> &requiredNumbers)
{
    ProcessVector(numbers);
    return VectorsAreEquals(numbers, requiredNumbers);
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

    // Из элементов, стоящих на нечетных позициях, вычитается сумму всех неотрицательных элементов
    BOOST_AUTO_TEST_CASE(evens_sub_sum_of_positive_numbers)
    {
        vector<double> numbers = { -1, 10, -3, 5 };
        vector<double> numbersRequired = { -16, 10, -18, 5 };
        SubEvensElementsWithSumOfPositives(numbers);
        BOOST_CHECK(VectorsAreEquals(numbers, numbersRequired));
    }

    // Элементы, стоящие на четных позициях массива умножает на 2, 
    // а из элементов, стоящих на нечетных позициях, вычитает сумму всех неотрицательных элементов
    BOOST_AUTO_TEST_CASE(odds_mul_by_2_and_evens_sub_sum_of_positive_numbers)
    {
        BOOST_CHECK(ProcessVectorEqual({ -1, 0, -3, 0 }, { -1, 0, -3, 0 }));

        BOOST_CHECK(ProcessVectorEqual({ 0, 0, 0 }, { 0, 0, 0 }));

        BOOST_CHECK(ProcessVectorEqual({ 1, 2.5, 3, 4.7, 5, 6.9, 7, 8.2, 9, 0 }, 
                                       { -46.3, 5, -44.3, 9.4, -42.3, 13.8, -40.3, 16.4, -38.3, 0 }));

        BOOST_CHECK(ProcessVectorEqual({ -1, -53.21, 1, 24.112, -213.521, 9842.124 }, 
                                       { -9868.236, -106.42, -9866.236, 48.224, -10080.757, 19684.248 }));
    }

BOOST_AUTO_TEST_SUITE_END()