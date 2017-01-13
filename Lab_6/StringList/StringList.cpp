#include "StringList.h"

CStringList::CStringList()
{
    Init();
}

CStringList::CStringList(const CStringList & list)
{
    Init();
    for (const std::string & elem : list)
    {
        PushBack(elem);
    }
}

CStringList::CStringList(CStringList && list)
{
    m_firstNode = std::move(list.m_firstNode);
    m_lastNode = list.m_lastNode;
    list.m_lastNode = nullptr;
    m_size = list.m_size;
    list.m_size = 0;
}

CStringList::~CStringList()
{
    Clear();
}

void CStringList::Init()
{
    m_firstNode = std::make_unique<ListNode>("", nullptr, nullptr);
    m_lastNode = new ListNode("", nullptr, nullptr);
    m_firstNode->next = std::unique_ptr<ListNode>(m_lastNode);
    m_lastNode->prev = m_firstNode.get();
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
        std::unique_ptr<ListNode> newNode = std::make_unique<ListNode>(data, m_lastNode->prev, std::move(m_lastNode->prev->next));
        ListNode *newNodePtr = newNode.get();
        m_lastNode->prev->next = std::move(newNode);
        m_lastNode->prev = newNodePtr;

        ++m_size;
    }
    catch (...)
    {
        throw std::runtime_error("Insertion failed");
    }
}

void CStringList::PushFront(const std::string & data)
{
    try
    {
        std::unique_ptr<ListNode> newNode = std::make_unique<ListNode>(data, m_firstNode.get(), std::move(m_firstNode->next));
        newNode->next->prev = newNode.get();
        m_firstNode->next = std::move(newNode);

        ++m_size;
    }
    catch (...)
    {
        throw std::runtime_error("Insertion failed");
    }
}

void CStringList::Insert(const CListIterator<std::string> & it, std::string data)
{
    if (it == begin() || it == rend())
    {
        PushFront(data);
    }
    else if (it == end() || it == rbegin())
    {
        PushBack(data);
    }
    else
    {
        try
        {
            std::unique_ptr<ListNode> newNode = std::make_unique<ListNode>(data, it->prev, std::move(it->prev->next));
            it->prev = newNode.get();
            newNode->prev->next = std::move(newNode);
            m_size++;
        }
        catch (...)
        {
            throw std::runtime_error("Insertion failed");
        }
    }
}

void CStringList::Clear()
{
    if (!m_lastNode || !m_firstNode)
    {
        return;
    }
    auto lastNode = std::move(m_lastNode->prev->next);
    while (m_lastNode->prev)
    {
        m_lastNode->prev->next = nullptr;
        m_lastNode->prev = m_lastNode->prev->prev;
    }
    m_firstNode->next = std::move(lastNode);
    m_lastNode->prev = m_firstNode.get();
    m_size = 0;
}

void CStringList::Erase(const CListIterator<std::string> & it)
{
    if (m_size == 0)
    {
        throw std::out_of_range("List is empty");
    }
    else if (it == end() || it == rend())
    {
        throw std::runtime_error("Unable to erase end iterator");
    }
    else if (m_size == 1)
    {
        Clear();
        return;
    }

    if (it == begin())
    {
         m_firstNode->next = std::move(it->next);
         m_firstNode->next->prev = m_firstNode.get();
    }
    else if (it == --end())
    {
        std::unique_ptr<ListNode> ptrToLast = std::move(it->next);
        m_lastNode->prev = it->prev;
        m_lastNode->prev->next = std::move(ptrToLast);
    }
    else
    {
        it->next->prev = it->prev;
        it->prev->next = std::move(it->next);
    }
    m_size--;
}

const std::string & CStringList::GetFirstElement() const
{
    if (m_firstNode->next.get() == m_lastNode)
    {
        throw std::runtime_error("List hasn`t first element");
    }
    else
    {
        return m_firstNode->next->data;
    }
}

const std::string & CStringList::GetLastElement() const
{
    if (m_lastNode->prev == m_firstNode.get())
    {
        throw std::runtime_error("List hasn`t last element");
    }
    else
    {
        return m_lastNode->prev->data;
    }
}

CListIterator<std::string> CStringList::begin()
{
    return CListIterator<std::string>(m_firstNode->next.get(), false);
}

CListIterator<std::string> CStringList::end()
{
    return CListIterator<std::string>(m_lastNode, false);
}

CListIterator<const std::string> CStringList::begin() const
{
    return CListIterator<const std::string>(m_firstNode->next.get(), false);
}

CListIterator<const std::string> CStringList::end() const
{
    return CListIterator<const std::string>(m_lastNode, false);
}

CListIterator<std::string> CStringList::rbegin()
{
    return CListIterator<std::string>(m_lastNode->prev, true);
}

CListIterator<std::string> CStringList::rend()
{
    return CListIterator<std::string>(m_firstNode.get(), true);
}

CListIterator<const std::string> CStringList::rbegin() const
{
    return CListIterator<const std::string>(m_lastNode->prev, true);
}

CListIterator<const std::string> CStringList::rend() const
{
    return CListIterator<const std::string>(m_firstNode.get(), true);
}

CListIterator<const std::string> CStringList::cbegin() const
{
    return CListIterator<const std::string>(m_firstNode->next.get(), false);
}

CListIterator<const std::string> CStringList::cend() const
{
    return CListIterator<const std::string>(m_lastNode, false);
}

CListIterator<const std::string> CStringList::crbegin() const
{
    return CListIterator<const std::string>(m_lastNode->prev, true);
}

CListIterator<const std::string> CStringList::crend() const
{
    return CListIterator<const std::string>(m_firstNode.get(), true);
}

CStringList& CStringList::operator=(CStringList const& rhs)
{
    Init();
    for (const std::string & elem : rhs)
    {
        PushBack(elem);
    }
    return *this;
}

CStringList& CStringList::operator=(CStringList && rhs)
{
    m_firstNode = std::move(rhs.m_firstNode);
    m_lastNode = rhs.m_lastNode;
    rhs.m_lastNode = nullptr;
    m_size = rhs.m_size;
    rhs.m_size = 0;
    return *this;
}