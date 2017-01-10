#pragma once
#include "stdafx.h" 

template <class T>
class CMyArrayNode
{
public:
    CMyArrayNode(T data, CMyArrayNode * prev, std::unique_ptr<CMyArrayNode> && next)
        : data(data)
        , prev(prev)
        , next(std::move(next))
    {

    }

    T data;
    std::unique_ptr<CMyArrayNode> next;
    CMyArrayNode *prev;
};