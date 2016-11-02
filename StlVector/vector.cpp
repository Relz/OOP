#include "stdafx.h"
#include <boost/range/algorithm/transform.hpp>

// Умножение каждого четного элемента вектора на 2
void MulOddsEltsBy2(std::vector<double> &numbers)
{
	for (size_t i = 1; i < numbers.size(); i += 2)
	{
		numbers[i] *= 2;
	}
}

// Вычитание из каждого нечетного элемента вектора сумму положительных элементов
void SubEvensElementsWithSumOfPositives(std::vector<double> &numbers)
{
	if (numbers.size() > 0)
	{
		double positiveNumSum = 0;
		for (double number : numbers)
		{
			positiveNumSum += (number > 0) ? number : 0;
		}
		for (size_t i = 0; i < numbers.size(); i += 2)
		{
			numbers[i] -= positiveNumSum;
		}
	}
}

void ProcessVector(std::vector<double> & numbers)
{
	SubEvensElementsWithSumOfPositives(numbers);
	MulOddsEltsBy2(numbers);
}