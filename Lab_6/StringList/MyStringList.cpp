#include "MyStringList.h"

CMyStringList::CMyStringList()
{
}

CMyStringList::iterator *CMyStringList::begin() const
{
    return m_begin;
}

CMyStringList::iterator *CMyStringList::end() const
{
    return m_end;
}

size_t CMyStringList::GetSize() const
{
    return m_size;
}

bool CMyStringList::IsEmpty() const
{
    return m_size == 0;
}

void CMyStringList::InsertFront(std::string const& str)
{

}

void CMyStringList::InsertBack(std::string const& str)
{

}

void CMyStringList::Insert(iterator *pos, std::string const& str)
{

}

void CMyStringList::Erase(iterator *pos)
{

}