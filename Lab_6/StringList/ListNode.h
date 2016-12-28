#pragma once
#include "stdafx.h" 

class ListNode
{
public:
    ListNode(const std::string & data, ListNode * prev, std::unique_ptr<ListNode> && next)
        : data(data)
        , prev(prev)
        , next(std::move(next))
    {

    }

    std::string data;
    std::unique_ptr<ListNode> next;
    ListNode *prev;
};