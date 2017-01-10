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

template<class T>
class CMyArrayIterator : public std::iterator<std::input_iterator_tag, T>
{
    friend class CMyArray;
public:
    CMyArrayIterator(CMyArrayNode* node, bool isReverse)
        : m_node(node)
        , m_isReverse(isReverse)
    {
    }

    bool operator==(CMyArrayIterator const& rhs) const
    {
        return m_node == rhs.m_node;
    }

    bool operator!=(CMyArrayIterator const& rhs) const
    {
        return m_node != rhs.m_node;
    }

    CMyArrayIterator& operator++()
    {
        if (m_node != nullptr)
        {
            m_node = (m_isReverse) ? m_node->prev : m_node = m_node->next.get();
        }
        return *this;
    }
    CMyArrayIterator& operator--()
    {
        if (m_node != nullptr)
        {
            m_node = (m_isReverse) ? m_node->next.get() : m_node = m_node->prev;
        }
        return *this;
    }

    T & operator*() const
    {
        return m_node->data;
    }

private:
    CMyArrayNode* m_node = nullptr;
    bool m_isReverse = false;

    CMyArrayNode* operator->() const
    {
        return m_node;
    }
};