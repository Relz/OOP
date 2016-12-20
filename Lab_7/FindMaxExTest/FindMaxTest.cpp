#include "stdafx.h"
#include "athlete.h"

#include "../FindMaxEx/FindMax.h"

BOOST_AUTO_TEST_SUITE(FindMax_function)

    BOOST_AUTO_TEST_CASE(cannot_find_in_empty_vector)
    {
        float max = NAN;
        BOOST_CHECK(!FindMax({}, max, [](const auto lhs, const auto rhs) {
            return (lhs < rhs);
        }));
    }

BOOST_AUTO_TEST_SUITE_END()