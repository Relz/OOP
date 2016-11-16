#include "stdafx.h"
#include "constant.h"

bool IsValidUpperBound(int upperBound)
{
    return (upperBound > 0 && upperBound <= MAX_UPPER_BOUND);
}

std::vector<bool> InitSieve(int upperBound)
{
    std::vector<bool> result(upperBound + 1, true);
    result[0] = result[1] = false;
    int sqrtUpperBound = static_cast<int>(round(sqrt(upperBound)));
    for (int i = MIN_PRIME_NUMBER; i <= sqrtUpperBound; ++i)
    {
        if (result[i])
        {
            int speed = (i == 2) ? i : i + i;
            for (int j = i * i; j <= upperBound; j += speed)
            {
                result[j] = false;
            }
        }
    }
    return result;
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
    std::set<int> result = {};
    if (IsValidUpperBound(upperBound) && upperBound >= MIN_PRIME_NUMBER && upperBound <= MAX_UPPER_BOUND)
    {
        std::vector<bool> sieve = InitSieve(upperBound);
        for (int i = MIN_PRIME_NUMBER; i <= upperBound; ++i)
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