#include "stdafx.h"
#include "MyArray.h"
#include <iostream>

int main(int argc, char *argv[])
{
    CMyArray<int> arr;
    arr.Append(1);
    arr.Resize(5);
    arr.Append(2);
    std::cout << arr[4];
    return 0;
}