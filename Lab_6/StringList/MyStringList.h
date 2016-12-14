#pragma once
#include "stdafx.h"

class CMyStringList
{
public:
    struct iterator
    {
        std::string value;
        iterator *next = nullptr;
        iterator *prev = nullptr;
    };

    CMyStringList();
    ~CMyStringList() = default;

    iterator *begin() const;
    iterator *end() const;
    size_t GetSize() const;
    bool IsEmpty() const;

    void InsertFront(std::string const& str);
    void InsertBack(std::string const& str);
    void Insert(iterator *pos, std::string const& str);
    void Erase(iterator *pos);
private:
    size_t m_size = 0;
    iterator *m_begin;
    iterator *m_end;
};

