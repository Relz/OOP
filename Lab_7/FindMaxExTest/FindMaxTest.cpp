#include "stdafx.h"
#include "athlete.h"

#include "../FindMaxEx/FindMax.h"

const Athlete Ivanov = { "Ivanov Ivan Ivanovich", 220.5, 100.5 };
const Athlete Petrov = { "Petrov Petr Petrovich", 150.8, 78.42 };
const Athlete Jay = { "Jay John Jamson", 100.5, 50.25 };
const Athlete Turchinov = { "Turchinov Nikolay Olegovich", 180.0, 50.20 };

const std::vector<Athlete> athletes = { Ivanov, Petrov, Jay, Turchinov };

BOOST_AUTO_TEST_SUITE(FindMax_function)

    BOOST_AUTO_TEST_CASE(cannot_find_in_empty_vector)
    {
        float max = NAN;
        BOOST_CHECK(!FindMax({}, max, [](const auto lhs, const auto rhs) {
            return (lhs < rhs);
        }));
        BOOST_CHECK(isnan(max));

        Athlete lessHeightAthlete = Ivanov;
        BOOST_CHECK(!FindMax({}, lessHeightAthlete, IsLessHeight));
        AreEquals(lessHeightAthlete, Ivanov);

        Athlete lessWeightAthlete = Ivanov;
        BOOST_CHECK(!FindMax({}, lessWeightAthlete, IsLessWeight));
        AreEquals(lessWeightAthlete, Ivanov);
    }

BOOST_AUTO_TEST_SUITE_END()