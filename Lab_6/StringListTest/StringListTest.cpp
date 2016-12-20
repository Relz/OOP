#include "stdafx.h"
#include "..\StringList\StringList.h"

struct StringListFixture
{
    CStringList stringList;
};

BOOST_FIXTURE_TEST_SUITE(CStringList_class, StringListFixture)

    BOOST_AUTO_TEST_CASE(can_get_begin_iterator)
    {
        BOOST_CHECK(!stringList.begin());
    }

BOOST_AUTO_TEST_SUITE_END()