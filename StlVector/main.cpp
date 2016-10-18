#include <iostream>
#include <iterator>
#include "stdafx.h"

using namespace std;

int main()
{
    cout << "Enter double numbers separated by spaces. Enter End of file symbol for exit. " << "\n";
    vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
    copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, ", "));
    return 0;
}