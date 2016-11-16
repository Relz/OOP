#include "stdafx.h"
#include "constant.h"
#include "primeNumbers.h"

using namespace std;

bool IsValidArgumentsCount(int argc)
{
    return (argc == ARG_COUNT);
}

int main(int argc, char * argv[])
{
    if (!IsValidArgumentsCount(argc))
    {
        cerr << "PrimeNumbersSetGenerator.exe <upperBound>" << "\n";
        return 1;
    }

    int upperBound = atoi(argv[1]);
    if (!IsValidUpperBound(upperBound))
    {
        cerr << "The upper bound must be from 1 to 100000000" << "\n";
        return 1;
    }

    set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);

    cout << primeNumbers.size() << "\n";
    PrintPrimeNumbersToOutput(primeNumbers);
    return 0;
}