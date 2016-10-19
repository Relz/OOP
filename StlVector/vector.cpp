#include "stdafx.h"
#include <boost/range/algorithm/transform.hpp>

// Умножение каждого четного элемента вектора на 2
void MulOddsEltsBy2(std::vector<double> &numbers)
{
	for (unsigned i = 1; i < numbers.size(); i += 2)
	{
		numbers[i % numbers.size()] *= 2;
	}
}

// Вычитание из каждого нечетного элемента вектора сумму положительных элементов
void SubEvensElementsWithPositives(std::vector<double> &numbers)
{
	if (numbers.size() > 0)
	{
		double positiveNumSum = 0;
		for (double number : numbers)
		{
			positiveNumSum += (number > 0) ? number : 0;
		}
		for (unsigned i = 1; i < numbers.size(); i += 2)
		{
			numbers[i % numbers.size()] += positiveNumSum;
		}
	}
}

void ProcessVector(std::vector<double> & numbers)
{
	SubEvensElementsWithPositives(numbers);
	MulOddsEltsBy2(numbers);
}