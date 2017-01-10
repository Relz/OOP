#pragma once

template <class T, class Less>
bool FindMax(std::vector<T> const& arr,
    T & maxValue,
    Less const& less)
{
    if (arr.empty())
    {
        return false;
    }
    maxValue = arr[0];
    for (T const& element : arr)
    {
        if (less(maxValue, element))
        {
            maxValue = element;
        }
    }
    return true;
}

template <class T>
bool FindMax(std::vector<T> const& arr,
    T & maxValue)
{
    if (arr.empty())
    {
        return false;
    }
    maxValue = arr[0];
    for (T const& element : arr)
    {
        if (maxValue< element)
        {
            maxValue = element;
        }
    }
    return true;
}