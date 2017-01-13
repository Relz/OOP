#pragma once
#include "stdafx.h" 
#include "ListNode.h"

template<typename T>
class CListIterator : public std::iterator<std::input_iterator_tag, T>
{
    friend class CStringList;
public:
    CListIterator(ListNode* node, bool isReverse)
        : m_node(node)
        , m_isReverse(isReverse)
    {
    }

    CListIterator(const CListIterator & list)
    {
        m_node = list.m_node;
        m_isReverse = list.m_isReverse;
    }

    CListIterator(CListIterator && list)
    {
        m_node = std::move(list.m_node);
        m_isReverse = std::move(list.m_isReverse);
    }

    bool operator==(CListIterator const& rhs) const
    {
        return (m_node == rhs.m_node && m_isReverse == rhs.m_isReverse);
    }

    bool operator!=(CListIterator const& rhs) const
    {
        return (m_node != rhs.m_node || m_isReverse != rhs.m_isReverse);
    }

    CListIterator& operator=(CListIterator const& rhs)
    {
        if (m_isReverse != rhs.m_isReverse)
        {
            throw (std::runtime_error("Iterators reversion are not equal"));
        }
        m_node = rhs.m_node;
        return *this;
    }

    CListIterator& operator=(CListIterator && rhs)
    {
        if (m_isReverse != rhs.m_isReverse)
        {
            throw (std::runtime_error("Iterators reversion are not equal"));
        }
        m_node = std::move(rhs.m_node);
        return *this;
    }

    CListIterator& operator++()
    {
        Increment();
        return *this;
    }
    CListIterator& operator--()
    {
        Decrement();
        return *this;
    }

    CListIterator operator++(int)
    {
        CListIterator tmp = *this;
        Increment();
        return tmp;
    }
    CListIterator operator--(int)
    {
        CListIterator tmp = *this;
        Decrement();
        return tmp;
    }

    T & operator*() const
    {
        if (!m_node)
        {
            throw std::runtime_error("Can't get null pointer iterator value");
        }
        if (!m_node->next)
        {
            throw std::runtime_error("Can't get end iterator value");
        }
        if (!m_node->prev)
        {
            throw std::runtime_error("Can't get previous for begin iterator value");
        }
        return m_node->data;
    }

    ListNode * operator->() const
    {
        return m_node;
    }

private:
    void Increment()
    {
        if (m_node != nullptr)
        {
            if (m_isReverse)
            {
                if (m_node->prev != nullptr)
                {
                    m_node = m_node->prev;
                }
            }
            else if (m_node->next)
            {
                m_node = m_node->next.get();
            }
        }
    }

    void Decrement()
    {
        if (m_node != nullptr)
        {
            if (m_isReverse)
            {
                if (m_node->next)
                {
                    m_node = m_node->next.get();
                }
            }
            else if (m_node->prev != nullptr)
            {
                m_node = m_node->prev;
            }
        }
    }

    ListNode* m_node = nullptr;
    bool m_isReverse = false;
};