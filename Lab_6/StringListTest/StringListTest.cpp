#include "stdafx.h"
#include "..\StringList\StringList.h"

void VerifyStringList(const CStringList & list, const std::vector<std::string> & expectedStrings)
{
    BOOST_CHECK_EQUAL(list.GetSize(), expectedStrings.size());

    size_t expectedStringPos = 0;
    for (auto it = list.cbegin(); it != list.cend(); ++it)
    {
        BOOST_CHECK_EQUAL(*it, expectedStrings[expectedStringPos]);
        expectedStringPos++;
    }
}

struct StringListFixture
{
    CStringList stringList;
    std::vector<std::string> stringVector = { "First", "Second", "Third", "Fourth", "Fifth" };
};

BOOST_FIXTURE_TEST_SUITE(CStringList_class, StringListFixture)

    BOOST_AUTO_TEST_SUITE(by_default)

        BOOST_AUTO_TEST_CASE(size_is_zero)
        {
            BOOST_CHECK_EQUAL(stringList.GetSize(), 0);
        }
        BOOST_AUTO_TEST_CASE(is_empty)
        {
            BOOST_CHECK(stringList.IsEmpty());
        }
        BOOST_AUTO_TEST_CASE(begin_is_nullptr_iterator)
        {
            BOOST_CHECK(stringList.begin() == CListIterator<std::string>(nullptr, false));
        }
        BOOST_AUTO_TEST_CASE(end_is_nullptr_iterator)
        {
            BOOST_CHECK(stringList.end() == CListIterator<std::string>(nullptr, false));
        }
        BOOST_AUTO_TEST_CASE(reversed_begin_is_nullptr_iterator)
        {
            BOOST_CHECK(stringList.rbegin() == CListIterator<std::string>(nullptr, true));
        }
        BOOST_AUTO_TEST_CASE(reversed_end_is_nullptr_iterator)
        {
            BOOST_CHECK(stringList.rend() == CListIterator<std::string>(nullptr, true));
        }
        BOOST_AUTO_TEST_CASE(cbegin_is_nullptr_iterator)
        {
            BOOST_CHECK(stringList.cbegin() == CListIterator<std::string>(nullptr, false));
        }
        BOOST_AUTO_TEST_CASE(cend_is_nullptr_iterator)
        {
            BOOST_CHECK(stringList.cend() == CListIterator<std::string>(nullptr, false));
        }
        BOOST_AUTO_TEST_CASE(crbegin_is_nullptr_iterator)
        {
            BOOST_CHECK(stringList.crbegin() == CListIterator<std::string>(nullptr, true));
        }
        BOOST_AUTO_TEST_CASE(crend_is_nullptr_iterator)
        {
            BOOST_CHECK(stringList.crend() == CListIterator<std::string>(nullptr, true));
        }
        BOOST_AUTO_TEST_CASE(cant_get_first_element_if_string_list_is_empty)
        {
            BOOST_CHECK_THROW(stringList.GetFirstElement(), std::runtime_error);
        }
        BOOST_AUTO_TEST_CASE(cant_get_last_element_if_string_list_is_empty)
        {
            BOOST_CHECK_THROW(stringList.GetLastElement(), std::runtime_error);
        }

    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_CASE(push_changes_size)
    {
        stringList.PushFront("First");
        BOOST_CHECK_EQUAL(stringList.GetSize(), 1);

        stringList.PushBack("Second");
        BOOST_CHECK_EQUAL(stringList.GetSize(), 2);
    }

    BOOST_AUTO_TEST_CASE(can_get_first_element)
    {
        for (size_t i = 0; i < stringVector.size(); ++i)
        {
            stringList.PushBack(stringVector[i]);
        }

        std::string firstElement = stringList.GetFirstElement();
        BOOST_CHECK_EQUAL(firstElement, stringVector.front());
    }

    BOOST_AUTO_TEST_CASE(can_get_last_element)
    {
        for (size_t i = 0; i < stringVector.size(); ++i)
        {
            stringList.PushBack(stringVector[i]);
        }

        std::string lastElement = stringList.GetLastElement();
        BOOST_CHECK_EQUAL(lastElement, stringVector.back());
    }

    BOOST_AUTO_TEST_CASE(can_be_cleared)
    {
        stringList.PushBack("0");
        stringList.PushBack("1");
        stringList.Clear();
        BOOST_CHECK_EQUAL(stringList.GetSize(), 0);
    }

    BOOST_AUTO_TEST_CASE(will_be_empty_after_destructor)
    {
        stringList.PushBack("0");
        stringList.PushBack("1");
        stringList.~CStringList();
        BOOST_CHECK_EQUAL(stringList.GetSize(), 0);
    }

    BOOST_AUTO_TEST_CASE(can_insert_element_into_iterator_position)
    {
        stringList.Insert(stringList.begin(), "0");
        BOOST_CHECK_EQUAL(*stringList.begin(), "0");

        stringList.Insert(stringList.begin(), "1");
        BOOST_CHECK_EQUAL(*stringList.begin(), "1");

        stringList.Insert(stringList.end(), "2");
        VerifyStringList(stringList, { "1" , "0" , "2" });
    }

    BOOST_AUTO_TEST_CASE(can_erase_element_at_iterator_position)
    {
        stringList.PushBack("0");
        stringList.PushBack("1");
        stringList.PushBack("2");
        stringList.PushBack("3");
        stringList.Erase(stringList.begin());
        VerifyStringList(stringList, { "1", "2", "3" });

        stringList.Erase(++stringList.begin());
        VerifyStringList(stringList, { "1", "3" });

        stringList.Erase(++stringList.begin());
        VerifyStringList(stringList, { "1" });

        stringList.Erase(stringList.begin());
        VerifyStringList(stringList, {});
        BOOST_CHECK(stringList.IsEmpty());
    }

    BOOST_AUTO_TEST_CASE(can_get_elements_from_range_based_for)
    {
        for (size_t i = 0; i < stringVector.size(); ++i)
        {
            stringList.PushBack(stringVector[i]);
        }

        size_t stringVectorPos = 0;
        for (auto string : stringList)
        {
            BOOST_CHECK_EQUAL(string, stringVector[stringVectorPos]);
            stringVectorPos++;
        }
    }

    BOOST_AUTO_TEST_CASE(have_reverse_iterators)
    {
        for (size_t i = 0; i < stringVector.size(); ++i)
        {
            stringList.PushBack(stringVector[i]);
        }

        size_t stringVectorPos = stringVector.size() - 1;
        for (auto it = stringList.rbegin(); it != stringList.rend(); ++it)
        {
            BOOST_CHECK_EQUAL(*it, stringVector[stringVectorPos]);
            stringVectorPos--;
        }
    }

    BOOST_AUTO_TEST_CASE(have_const_reverse_iterators)
    {
        for (size_t i = 0; i < stringVector.size(); ++i)
        {
            stringList.PushBack(stringVector[i]);
        }

        size_t stringVectorPos = stringVector.size() - 1;
        for (auto it = stringList.crbegin(); it != stringList.crend(); ++it)
        {
            BOOST_CHECK_EQUAL(*it, stringVector[stringVectorPos]);
            stringVectorPos--;
        }
    }

    BOOST_AUTO_TEST_CASE(cant_erase_empty_string_list)
    {
        BOOST_REQUIRE_THROW(stringList.Erase(stringList.begin()), std::out_of_range);
    }

    BOOST_AUTO_TEST_CASE(have_copy_constructor)
    {
        for (size_t i = 0; i < stringVector.size(); ++i)
        {
            stringList.PushBack(stringVector[i]);
        }

        CStringList copiedList(stringList);
        VerifyStringList(stringList, stringVector);
        VerifyStringList(copiedList, stringVector);
    }

BOOST_AUTO_TEST_SUITE_END()