#include "stdafx.h"

bool IsValidUpperBound(int upperBound)
{
	return (upperBound > 0 && upperBound <= MAX_UPPER_BOUND);
}

std::vector<bool> InitSieve(size_t upperBound)
{
	std::vector<bool> result(upperBound + 1, true);
	result[0] = result[1] = false;
	for (size_t i = MIN_PRIME_NUMBER; i * i <= upperBound; ++i)
	{
		if (result[i])
		{
			for (size_t j = i * i; j <= upperBound; j += i)
			{
				result[j] = false;
			}
		}
	}
	return result;
}

std::set<int> GeneratePrimeNumbersSet(size_t upperBound)
{
	std::set<int> result = {};
	if (IsValidUpperBound(upperBound) && upperBound >= MIN_PRIME_NUMBER && upperBound <= MAX_UPPER_BOUND)
	{
		std::vector<bool> sieve = InitSieve(upperBound);
		for (size_t i = MIN_PRIME_NUMBER; i <= upperBound; ++i)
		{
			if (sieve[i])
			{
				result.emplace_hint(result.end(), i);
			}
		}
	}
	return result;
}

void PrintPrimeNumbersToOutput(std::set<int> const &primeNumbers)
{
	std::copy(primeNumbers.begin(), primeNumbers.end(), std::ostream_iterator<int>(std::cout, " "));
}