#include "stdafx.h"
#include "../MyArray/MyArray.h"

using namespace std;

struct ArrayItem
{
    ArrayItem(int value = 0) : value(value)
    {}
    int value;
};

struct EmptyStringArray
{
    CMyArray<ArrayItem> arr;
};

BOOST_FIXTURE_TEST_SUITE(MyArray, EmptyStringArray)
    BOOST_AUTO_TEST_SUITE(by_default)
        BOOST_AUTO_TEST_CASE(is_empty)
        {
            BOOST_CHECK_EQUAL(arr.GetSize(), 0u);
        }
        BOOST_AUTO_TEST_CASE(has_0_capacity)
        {
            BOOST_CHECK_EQUAL(arr.GetCapacity(), 0u);
        }
    BOOST_AUTO_TEST_SUITE_END()
    BOOST_AUTO_TEST_SUITE(after_appending_an_item)
        BOOST_AUTO_TEST_CASE(increases_its_size_and_capacity)
        {
            arr.Append(ArrayItem());
            BOOST_CHECK_EQUAL(arr.GetSize(), 1u);
            BOOST_CHECK_EQUAL(arr.GetCapacity(), 1u);
            arr.Append(ArrayItem(1));
            BOOST_CHECK_EQUAL(arr.GetSize(), 2u);
            BOOST_CHECK_EQUAL(arr.GetCapacity(), 2u);
            arr.Append(ArrayItem(2));
            BOOST_CHECK_EQUAL(arr.GetSize(), 3u);
            BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);
            arr.Append(ArrayItem(3));
            BOOST_CHECK_EQUAL(arr.GetSize(), 4u);
            BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);
            BOOST_CHECK_EQUAL(arr[0].value, 0);
            BOOST_CHECK_EQUAL(arr[1].value, 1);
            BOOST_CHECK_EQUAL(arr[2].value, 2);
            BOOST_CHECK_EQUAL(arr[3].value, 3);
            BOOST_CHECK_THROW(arr[4].value, std::out_of_range);
        }
        BOOST_AUTO_TEST_CASE(it_becomes_available_at_the_back)
        {
            arr.Append(1);
            BOOST_CHECK_EQUAL(arr.GetBack().value, 1);
            arr.Append(2);
            BOOST_CHECK_EQUAL(arr.GetBack().value, 2);
            arr.Append(3);
            BOOST_CHECK_EQUAL(arr.GetBack().value, 3);
            arr.Append(4);
            BOOST_CHECK_EQUAL(arr.GetBack().value, 4);
        }
    BOOST_AUTO_TEST_SUITE_END()
        BOOST_AUTO_TEST_SUITE(after_copy_construction)
        BOOST_AUTO_TEST_CASE(has_size_capacity_equal_to_size_of_original_array)
    {
        for (auto i = 0; i < 6; ++i)
        {
            arr.Append(i);
        }
        BOOST_CHECK_NE(arr.GetSize(), arr.GetCapacity());

        auto copy(arr);
        BOOST_CHECK_EQUAL(copy.GetSize(), arr.GetSize());
        BOOST_CHECK_EQUAL(copy.GetCapacity(), arr.GetSize());
    }
    BOOST_AUTO_TEST_SUITE_END()
    BOOST_AUTO_TEST_SUITE(after_resizing)
        BOOST_AUTO_TEST_CASE(has_changed_size)
        {
            arr.Resize(5);
            BOOST_CHECK_EQUAL(arr.GetSize(), 5);
        }
        BOOST_AUTO_TEST_CASE(has_itialized_to_default_type_value_if_new_size_is_more)
        {
            arr.Resize(2);
            BOOST_CHECK_EQUAL(arr[0].value, ArrayItem().value);
            BOOST_CHECK_EQUAL(arr[1].value, ArrayItem().value);
        }
    BOOST_AUTO_TEST_SUITE_END()
    BOOST_AUTO_TEST_SUITE(after_clearing)
        BOOST_AUTO_TEST_CASE(has_no_size)
        {
            arr.Clear();
            BOOST_CHECK_EQUAL(arr.GetSize(), 0);
        }
        BOOST_AUTO_TEST_CASE(cannot_get_element_by_index)
        {
            arr.Clear();
            BOOST_CHECK_THROW(arr[0], std::out_of_range);
        }
    BOOST_AUTO_TEST_SUITE_END()
    BOOST_AUTO_TEST_CASE(can_be_assigned)
    {
        CMyArray<ArrayItem> newArr;
        newArr.Append(ArrayItem(1));
        newArr.Append(ArrayItem(2));
        newArr.Append(ArrayItem(3));
        arr = newArr;
        BOOST_CHECK_EQUAL(arr.GetSize(), 3);
        BOOST_CHECK_EQUAL(arr[0].value, 1);
        BOOST_CHECK_EQUAL(arr[1].value, 2);
        BOOST_CHECK_EQUAL(arr[2].value, 3);
    }
BOOST_AUTO_TEST_SUITE_END()