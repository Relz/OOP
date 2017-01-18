#pragma once
#include "stdafx.h" 
#include "ListNode.h"

template<typename T>
class CListIterator : public std::iterator<std::input_iterator_tag, T>
{
    friend class CStringList;
public:
    CListIterator(ListNode* node)
        : m_node(node)
    {
    }

    CListIterator(const CListIterator & list)
        : m_node(list.m_node)
    {
    }

    CListIterator(CListIterator && list)
        : m_node(std::move(list.m_node))
    {
    }

    bool operator==(CListIterator const& rhs) const
    {
        return (m_node == rhs.m_node);
    }

    bool operator!=(CListIterator const& rhs) const
    {
        return (m_node != rhs.m_node);
    }

    CListIterator& operator=(CListIterator const& rhs)
    {
        m_node = rhs.m_node;
        return *this;
    }

    CListIterator& operator=(CListIterator && rhs)
    {
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
        return GetValue();
    }

private:
    void Increment()
    {
        if (m_node != nullptr && m_node->next)
        {
            m_node = m_node->next.get();
        }
    }

    void Decrement()
    {
        if (m_node != nullptr && m_node->prev)
        {
            m_node = m_node->prev;
        }
    }

    T & GetValue() const
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

    ListNode* m_node = nullptr;
    bool m_isReverse = false;
};

template<typename T>
class CListIteratorReverse : public std::iterator<std::input_iterator_tag, T>
{
    friend class CStringList;
public:
    CListIteratorReverse(ListNode* node)
        : m_node(node)
    {
    }

    CListIteratorReverse(const CListIteratorReverse & list)
        : m_node(list.m_node)
    {
    }

    CListIteratorReverse(CListIteratorReverse && list)
        : m_node(std::move(list.m_node))
    {
    }

    bool operator==(CListIteratorReverse const& rhs) const
    {
        return (m_node == rhs.m_node);
    }

    bool operator!=(CListIteratorReverse const& rhs) const
    {
        return (m_node != rhs.m_node);
    }

    CListIteratorReverse& operator=(CListIteratorReverse const& rhs)
    {
        m_node = rhs.m_node;
        return *this;
    }

    CListIteratorReverse& operator=(CListIteratorReverse && rhs)
    {
        m_node = std::move(rhs.m_node);
        return *this;
    }

    CListIteratorReverse& operator++()
    {
        Increment();
        return *this;
    }
    CListIteratorReverse& operator--()
    {
        Decrement();
        return *this;
    }

    CListIteratorReverse operator++(int)
    {
        CListIterator tmp = *this;
        Increment();
        return tmp;
    }
    CListIteratorReverse operator--(int)
    {
        CListIterator tmp = *this;
        Decrement();
        return tmp;
    }

    T & operator*() const
    {
        return GetValue();
    }

private:
    void Increment()
    {
        if (m_node != nullptr && m_node->prev)
        {
            m_node = m_node->prev;
        }
    }

    void Decrement()
    {
        if (m_node != nullptr && m_node->next)
        {
            m_node = m_node->next.get();
        }
    }

    T & GetValue() const
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

    ListNode* m_node = nullptr;
    bool m_isReverse = true;
};