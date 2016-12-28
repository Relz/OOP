#include "StringList.h"

CStringList::CStringList(CStringList & list)
{
    CStringList stringList;
    for (const std::string & elem : list)
    {
        stringList.PushBack(elem);
    }
    std::swap(m_firstNode, stringList.m_firstNode);
    std::swap(m_lastNode, stringList.m_lastNode);
    m_size = stringList.m_size;
}

CStringList::~CStringList()
{
    while (m_lastNode)
    {
        m_lastNode->next = nullptr;
        m_lastNode = m_lastNode->prev;
    }
    m_firstNode = nullptr;
    m_size = 0;
}

size_t CStringList::GetSize() const
{
    return m_size;
}

bool CStringList::IsEmpty() const
{
    return m_size == 0;
}

void CStringList::PushBack(const std::string & data)
{
    try
    {

        std::unique_ptr<ListNode> newNode = std::make_unique<ListNode>(data, m_lastNode, nullptr);
        ListNode *newLastNode = newNode.get();
        if (m_lastNode)
        {
            m_lastNode->next = std::move(newNode);
        }
        else
        {
            m_firstNode = std::move(newNode);
        }
        m_lastNode = newLastNode;
        m_lastNode->next = nullptr;

        ++m_size;
    }
    catch (...)
    {
        throw;
    }
}

void CStringList::PushFront(const std::string & data)
{
    try
    {
        std::unique_ptr<ListNode> newNode = InsertOnTheEdge(data, nullptr, std::move(m_firstNode));
        if (!newNode->next)
        {
            m_lastNode = newNode.get();
        }
        m_firstNode = std::move(newNode);
        m_firstNode->prev = nullptr;

        m_size++;
    }
    catch (...)
    {
        throw;
    }
}

std::unique_ptr<ListNode> CStringList::InsertOnTheEdge(const std::string & data, ListNode * prev, std::unique_ptr<ListNode> && next)
{
    try
    {
        std::unique_ptr<ListNode> newNode = std::make_unique<ListNode>(data, prev, std::move(next));

        if (newNode->prev)
        {
            newNode->prev->next = std::move(newNode);
        }
        else if (newNode->next)
        {
            newNode->next->prev = newNode.get();
        }
        return newNode;
    }
    catch (...)
    {
        throw;
    }
}



void CStringList::Clear()
{
    while (m_lastNode)
    {
        m_lastNode->next = nullptr;
        m_lastNode = m_lastNode->prev;
    }
    m_firstNode = nullptr;
    m_size = 0;
}


void CStringList::Insert(const CListIterator<std::string> & it, std::string data)
{
    if (it == begin())
    {
        PushFront(data);
    }
    else if (it == end())
    {
        PushBack(data);
    }
    else
    {
        try
        {
            auto node = std::make_unique<ListNode>(data, it->prev, std::move(it->prev->next));
            it->prev = std::move(node.get());
            node->prev->next = std::move(node);
        }
        catch (...)
        {
            throw;
        }
    }
}


void CStringList::Erase(const CListIterator<std::string> & it)
{
    if (m_size == 0)
    {
        throw std::out_of_range("List is empty");
    }
    else if (m_size == 1)
    {
        Clear();
        return;
    }

    auto pEnd = begin();
    for (size_t i = 0; i < m_size - 1; ++i)
    {
        pEnd = ++pEnd;
    }

    if (it == begin())
    {
         m_firstNode = std::move(it->next);
         m_firstNode->prev = nullptr;
    }
    else if (it == pEnd)
    {
        m_lastNode = std::move(it->prev);
        m_lastNode->next = nullptr;
    }
    else
    {
        it->next->prev = std::move(it->prev);
        it->prev->next = std::move(it->next);
    }

    if (m_size > 0)
    {
        m_size--;
    }
}

std::string &CStringList::GetFirstElement()
{
    if (m_firstNode != nullptr)
    {
        return m_firstNode->data;
    }
    else
    {
        throw std::runtime_error("List hasn`t first element");
    }
}

const std::string & CStringList::GetFirstElement() const
{
    if (m_firstNode != nullptr)
    {
        return m_firstNode->data;
    }
    else
    {
        throw std::runtime_error("List hasn`t first element");
    }
}

std::string &CStringList::GetLastElement()
{
    if (m_lastNode != nullptr)
    {
        return m_lastNode->data;
    }
    else
    {
        throw std::runtime_error("List hasn`t last element");
    }
}

const std::string & CStringList::GetLastElement() const
{
    if (m_lastNode != nullptr)
    {
        return m_lastNode->data;
    }
    else
    {
        throw std::runtime_error("List hasn`t last element");
    }
}

CListIterator<std::string> CStringList::begin()
{
    return CListIterator<std::string>(m_firstNode.get(), false);
}

CListIterator<std::string> CStringList::end()
{
    return (m_lastNode != nullptr) 
        ? CListIterator<std::string>(m_lastNode->next.get(), false) 
        : CListIterator<std::string>(m_lastNode, false);
}

CListIterator<std::string> CStringList::rbegin()
{
    return CListIterator<std::string>(m_lastNode, true);
}

CListIterator<std::string> CStringList::rend()
{
    return (m_firstNode != nullptr)
        ? CListIterator<std::string>(m_firstNode->prev, true)
        : CListIterator<std::string>(m_firstNode.get(), true);
}

const CListIterator<std::string> CStringList::cbegin() const
{
    return CListIterator<std::string>(m_firstNode.get(), false);
}

const CListIterator<std::string> CStringList::cend() const
{
    return (m_lastNode != nullptr)
        ? CListIterator<std::string>(m_lastNode->next.get(), false)
        : CListIterator<std::string>(m_lastNode, false);
}

const CListIterator<std::string> CStringList::crbegin() const
{
    return CListIterator<std::string>(m_lastNode, true);
}

const CListIterator<std::string> CStringList::crend() const
{
    return (m_firstNode != nullptr)
        ? CListIterator<std::string>(m_firstNode->prev, true)
        : CListIterator<std::string>(m_firstNode.get(), true);
}