#include "stdafx.h"
#include <vector>
#include "StringList.h"

int main(int argc, char *argv[])
{
    CStringList vect;
    vect.InsertFront("0");
    vect.InsertFront("1");
    vect.InsertFront("2");
    auto beg = vect.begin();
    return 0;
}