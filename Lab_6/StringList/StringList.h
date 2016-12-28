#pragma once
#include "stdafx.h"
#include "ListNode.h"
#include "ListIterator.h"

class CStringList
{
    friend class ListNode;
    friend class CListIterator<std::string>;
public:
    CStringList() = default;
    CStringList(CStringList & list);
    ~CStringList();

    size_t GetSize() const;
    bool IsEmpty() const;

    void PushBack(const std::string & data);
    void PushFront(const std::string & data);
    void Clear();

    void CStringList::Insert(const CListIterator<std::string> & it, std::string data);
    void CStringList::Erase(const CListIterator<std::string> & it);

    std::string & GetLastElement();
    const std::string & GetLastElement() const;

    std::string & GetFirstElement();
    const std::string & GetFirstElement() const;


    CListIterator<std::string> begin();
    CListIterator<std::string> end();

    const CListIterator<std::string> cbegin() const;
    const CListIterator<std::string> cend() const;

    CListIterator<std::string> rbegin();
    CListIterator<std::string> rend();

    const CListIterator<std::string> crbegin() const;
    const CListIterator<std::string> crend() const;

private:
    std::unique_ptr<ListNode> CStringList::InsertOnTheEdge(const std::string & data, ListNode * prev, std::unique_ptr<ListNode> && next);
    size_t m_size = 0;
    std::unique_ptr<ListNode> m_firstNode = nullptr;
    ListNode * m_lastNode = nullptr;

};