#pragma once

#include <new>
#include <algorithm>

template <typename T>
class CMyArray
{
public:
    CMyArray() = default;

    CMyArray(const CMyArray& arr)
    {
        CopyArray(arr);
    }

    CMyArray(CMyArray && arr)
    {
        MoveArray(arr);
    }

    void Append(const T & value)
    {
        if (m_end == m_endOfCapacity) // no free space
        {
            size_t newCapacity = std::max(1u, GetCapacity() * 2);

            auto newBegin = RawAlloc(newCapacity);
            T *newEnd = newBegin;
            try
            {
                CopyItems(m_begin, m_end, newBegin, newEnd);
                // ������������ ����� value �� ������ newItemLocation
                new (newEnd)T(value);
                ++newEnd;
            }
            catch (...)
            {
                DeleteItems(newBegin, newEnd);
                throw;
            }
            DeleteItems(m_begin, m_end);

            // ������������� �� ������������� ������ ��������� ���������
            m_begin = newBegin;
            m_end = newEnd;
            m_endOfCapacity = m_begin + newCapacity;
        }
        else // has free space
        {
            new (m_end) T(value);
            ++m_end;
        }
    }

    T & GetBack()
    {
        assert(GetSize() != 0u);
        return m_end[-1];
    }

    const T & GetBack()const
    {
        assert(GetSize() != 0u);
        return m_end[-1];
    }

    size_t GetSize()const
    {
        return m_end - m_begin;
    }

    size_t GetCapacity()const
    {
        return m_endOfCapacity - m_begin;
    }
    ~CMyArray()
    {
        DeleteItems(m_begin, m_end);
    }

    T &operator[](size_t index)
    {
        if (index >= GetSize())
        {
            throw std::out_of_range("MyArray: Out of range");
        }
        size_t currentIndex = 0;
        T *current = m_begin;
        while (currentIndex != index)
        {
            current++;
            currentIndex++;
        }
        return *current;
    }

    T &operator[](size_t index) const
    {
        if (index >= GetSize())
        {
            throw std::out_of_range("MyArray: Out of range");
        }
        size_t currentIndex = 0;
        T *current = m_begin;
        while (currentIndex != index)
        {
            current++;
            currentIndex++;
        }
        return *current;
    }

    void Resize(size_t newSize)
    {
        size_t currentSize = GetSize();
        while (newSize < currentSize)
        {
            m_end->~T();
            m_end--;
            currentSize--;
        }
        while (newSize > currentSize)
        {
            Append(T());
            currentSize++;
        }
    }

    void Clear()
    {
        DeleteItems(m_begin, m_end);
    }

    CMyArray & operator=(CMyArray const& r)
    {
        CopyArray(r);
        return *this;
    }

    CMyArray & operator=(CMyArray && r)
    {
        MoveArray(r);
        return *this;
    }

private:
    static void DeleteItems(T *begin, T *end)
    {
        // ��������� ������ ��������
        DestroyItems(begin, end);
        // ����������� ������� ������ ��� �� ��������
        RawDealloc(begin);
    }

    // �������� �������� �� �������� ������� � to, ���������� newEnd
    static void CopyItems(const T *srcBegin, T *srcEnd, T * const dstBegin, T * & dstEnd)
    {
        for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
        {
            // Construct "T" at "dstEnd" as a copy of "*begin"
            new (dstEnd)T(*srcBegin);
        }
    }

    static void DestroyItems(T *from, T *to)
    {
        // dst - ����� ������, ��� ��������������� �������� ���� ��������� ����������
        // to - ������ ������������������ ������
        while (to != from)
        {
            --to;
            // ���� �������� ���������� ��� ���������� ���� T
            to->~T();
        }
    }

    static T *RawAlloc(size_t n)
    {
        size_t memSize = n * sizeof(T);
        T *p = static_cast<T*>(malloc(memSize));
        if (!p)
        {
            throw std::bad_alloc();
        }
        return p;
    }

    static void RawDealloc(T *p)
    {
        free(p);
    }

private:
    void CopyArray(const CMyArray& arr)
    {
        const auto size = arr.GetSize();
        if (size != 0)
        {
            m_begin = RawAlloc(size);
            try
            {
                CopyItems(arr.m_begin, arr.m_end, m_begin, m_end);
                m_endOfCapacity = m_end;
            }
            catch (...)
            {
                DeleteItems(m_begin, m_end);
                throw;
            }
        }
    }

    void MoveArray(CMyArray& arr)
    {
        const auto size = arr.GetSize();
        if (size != 0)
        {
            m_begin = RawAlloc(size);
            try
            {
                *this = std::move(arr);
                m_endOfCapacity = m_end;
            }
            catch (...)
            {
                DeleteItems(m_begin, m_end);
                throw;
            }
        }
    }

    T *m_begin = nullptr;
    T *m_end = nullptr;
    T *m_endOfCapacity = nullptr;
};