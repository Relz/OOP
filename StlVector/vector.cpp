#include "stdafx.h"
#include "vector.h"

// Умножение каждого четного элемента вектора на число (по умолчанию на 2)
void MulOddsElements(std::vector<double> &numbers, double multiplier)
{
	for (unsigned i = 0; i < numbers.size(); i += 2)
	{
		numbers[i % numbers.size()] *= 2;
	}
}

// Вычитание каждого нечетного элемента вектора сумму положительных элементов
void SubEvensElements(std::vector<double> &numbers)
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
	SubEvensElements(numbers);
	MulOddsElements(numbers, 2);
}