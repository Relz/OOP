#pragma once
#include "stdafx.h"
#include "ListNode.h"
#include "ListIterator.h"

class CStringList
{
public:
    CStringList();
    ~CStringList();

    CStringList(const CStringList & list);
    CStringList(CStringList && list);

    CStringList& operator=(CStringList const& rhs);
    CStringList& operator=(CStringList && rhs);

    void Copy(CStringList const& rhs);
    void Move(CStringList && rhs);
    
    size_t GetSize() const;
    bool IsEmpty() const;

    void PushBack(const std::string & data);
    void PushFront(const std::string & data);
    void Clear();

    void Insert(const CListIterator<std::string> & it, std::string data);
    void Erase(const CListIterator<std::string> & it);

    const std::string & GetLastElement() const;
    const std::string & GetFirstElement() const;

    std::string & GetLastElement();
    std::string & GetFirstElement();

    CListIterator<std::string> begin();
    CListIterator<std::string> end();

    CListIterator<const std::string> begin() const;
    CListIterator<const std::string> end() const;

    CListIterator<const std::string> cbegin() const;
    CListIterator<const std::string> cend() const;

    CListIteratorReverse<std::string> rbegin();
    CListIteratorReverse<std::string> rend();

    CListIteratorReverse<const std::string> rbegin() const;
    CListIteratorReverse<const std::string> rend() const;

    CListIteratorReverse<const std::string> crbegin() const;
    CListIteratorReverse<const std::string> crend() const;

private:
    void Init();

    size_t m_size = 0;
    std::unique_ptr<ListNode> m_firstNode = nullptr;
    ListNode *m_lastNode = nullptr;

};