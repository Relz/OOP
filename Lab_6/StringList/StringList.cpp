#include "StringList.h"

CStringList::CStringList()
{
}

CStringList::CIterator CStringList::begin() const
{
    return CIterator(m_begin.get());
}

CStringList::CIterator CStringList::end() const
{
    return m_end;
}

size_t CStringList::GetSize() const
{
    return m_size;
}

bool CStringList::IsEmpty() const
{
    return m_size == 0;
}

void CStringList::InsertFront(std::string const& data)
{
    std::unique_ptr<Node> newNode = std::make_unique<Node>(data, nullptr, nullptr);
    if (m_end)
    {
        //m_begin->prev = move(newNode).get();
        //newNode->next = move(m_begin);
    }
    else
    {
        m_end = move(newNode).get();
    }
    //m_begin = move(newNode);
    ++m_size;
}

void CStringList::InsertBack(std::string const& data)
{
    std::unique_ptr<Node> newNode = std::make_unique<Node>(data, m_end, nullptr);
    if (m_end)
    {
        m_end->next = move(newNode);
    }
    else
    {
        m_begin = move(newNode);
    }
    m_end = newNode.get();
    ++m_size;
}

void CStringList::Insert(CIterator *pos, std::string const& str)
{

}

void CStringList::Erase(CIterator *pos)
{

}

CStringList::CIterator::CIterator(Node * node)
    :m_node(node)
{
}

std::string & CStringList::CIterator::operator*() const
{
    return m_node->data;
}

CStringList::CIterator & CStringList::CIterator::operator++()
{
    m_node = m_node->next.get();
    return *this;
}

std::string & CStringList::GetBackElement()
{
	return m_end->data;
}

std::string const& CStringList::GetBackElement() const
{
	return m_end->data;
}