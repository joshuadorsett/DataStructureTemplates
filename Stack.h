//
// Created by Joshua Dorsett on 9/28/20.
//

#ifndef SRC_STACK_H
#define SRC_STACK_H

#include <cstddef>
#include <algorithm>
#include <iostream>

template <typename type>
class Stack
{
private:
    type* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity{};

    void ReAllocate(const size_t& newCapacity)
    {
        type* newBlock = (type*)::operator new(m_Capacity * sizeof(type));
        size_t size = m_Size;
        if (newCapacity < size)
        {
            size = newCapacity;
        }
        for (int i = 0; i < size; i++)
        {
            newBlock[i] = std::move(m_Data[i]);
        }
        for (int i = 0; i < size; i++)
        {
            m_Data[i].~type();        }
        ::operator delete(m_Data, m_Size * sizeof(type));
        m_Data = newBlock;
        m_Capacity = newCapacity;
        std::cout << "re-allocating....\n" ;
    }

public:
    Stack()
    {
        ReAllocate(8);
        std::cout << "init size: " << m_Size << "\n";
        std::cout << "init cap: " << m_Capacity << "\n";
        if (m_Size > m_Capacity)
            m_Capacity = m_Size;
    }

    ~Stack()
    {
        Clear();
        ::operator delete(m_Data, m_Size * sizeof(type));
        std::cout << "Stack destroyed\n";
    }


    void Push(const type& data)
    {
        if ( m_Size >= m_Capacity)
            ReAllocate(m_Capacity * 1.5 );
        m_Data[m_Size] = data;
        m_Size++;
        std::cout << "[lValue] " << data << " was pushed on the stack\n";
    }
    void Push(type&& data)
    {
        if ( m_Size >= m_Capacity)
            ReAllocate(m_Capacity + m_Capacity*2 );
        m_Data[m_Size] = std::move(data);
        m_Size++;
        std::cout << "[rValue] " << data << " was pushed on the stack\n";
    }

    const type& Pop()
    {
        std::cout << "value: " << m_Data[--m_Size] << " popped off the stack\n";
        m_Data[m_Size].~type();
        return m_Data[m_Size];
    }

    void Clear()
    {
        for(int i = 0; i < m_Size; i++)
            m_Data[i].~type();
        m_Size = 0;
        std::cout << "Stack cleared\n";
    }

    type Get()
    {
        return m_Data[m_Size-1];
    }

    size_t Size() const
    {
        return m_Size;
    }

    size_t Cap() const
    {
        return m_Capacity;
    }

    bool operator==(const Stack<type>& other) const
    {
        if (m_Size != other.Size())
            return false;
        for (int i = 0; i < m_Size; i++)
        {
            if(m_Data[i] != other[i])
                return false;
        }
        return true;
    }

};

#endif //SRC_STACK_H
