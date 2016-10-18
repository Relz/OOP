#define BOOST_TEST_INCLUDED
#include <boost/test/unit_test.hpp>

#define BOOST_TEST_NO_MAIN
#include <boost/test/included/unit_test.hpp>

#include "../StlVector/vector.h"

using namespace std;

bool VectorsAreEqual(vector<double> const &x, vector<double> const &y)
{
    return x == y;
}

BOOST_AUTO_TEST_SUITE(ProcessVectorTest)

// Создает пустой вектор из пустого вектора
BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
{
    vector<double> emptyVector;
    ProcessVector(emptyVector);
    BOOST_CHECK(emptyVector.empty());
}

BOOST_AUTO_TEST_SUITE_END()