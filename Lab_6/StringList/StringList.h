#pragma once
#include "stdafx.h"

class CStringList
{
    struct Node
    {
        Node(std::string const& data, Node * prev, std::unique_ptr<Node> && next)
            : data(data)
            , prev(prev)
            , next(std::move(next))
        {
        }
        std::string data;
        std::unique_ptr<Node> next = nullptr;
        Node *prev = nullptr;
    };
public:
    class CIterator
    {
        friend CStringList;
        CIterator(Node *node);
    public:
        CIterator() = default;
        std::string & operator*()const;
        CIterator & operator++();
    private:
        Node *m_node = nullptr;
    };

    CStringList();
    ~CStringList() = default;

    CIterator begin() const;
    CIterator end() const;
    size_t GetSize() const;
    bool IsEmpty() const;
    std::string & CStringList::GetBackElement();
    std::string const& CStringList::GetBackElement() const;

    void InsertFront(std::string const& data);
    void InsertBack(std::string const& data);
    void Insert(CIterator *pos, std::string const& data);
    void Erase(CIterator *pos);
private:
    size_t m_size = 0;
    std::unique_ptr<Node> m_begin;
    Node *m_end = nullptr;
};

