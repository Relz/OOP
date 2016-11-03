#include "stdafx.h"

using namespace std;

// Проверка достаточности параметров запуска программы
bool IsValidArgumentsCount(int argc)
{
	return (argc == ARG_COUNT);
}

// Входит ли полученный параметр - вехрняя граница в допустимый интервал
bool IsValidUpperBound(int upperBound)
{
	return (upperBound > 0 && upperBound <= MAX_UPPER_BOUND);
}

int main(int argc, char * argv[])
{
	if (!IsValidArgumentsCount(argc))
	{
		cout << "PrimeNumbersSetGenerator.exe <upperBound>" << "\n";
		return 1;
	}

	int upperBound = atoi(argv[1]);
	if (!IsValidUpperBound(upperBound))
	{
		cout << "The upper bound must be from 1 to 100000000" << "\n";
		return 1;
	}
	return 0;
}