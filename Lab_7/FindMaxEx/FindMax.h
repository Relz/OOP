#pragma once

template <class T, class Less>
bool FindMax(std::vector<T> const& arr, T & maxValue, Less const& less)
{
    if (arr.empty())
    {
        return false;
    }
    return true;
}