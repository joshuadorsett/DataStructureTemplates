//
// Created by Joshua Dorsett on 9/27/20.
//

#include <cstddef>
#include <cstdlib>

#ifndef SRC_VECTOR_H
#define SRC_VECTOR_H
template<typename type>
class DynamicArray
{
private:
    type* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;

    void ReAllocate(const size_t& newCapacity)
    {
        type* newBlock = new type[newCapacity];
        size_t size = m_Size;
        if (newCapacity < size)
        {
            size = newCapacity;
        }
        for (int i = 0; i < size; i++)
        {
            newBlock[i] = std::move(m_Data[i]);
        }
        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
        std::cout << "re-allocating....\n" ;

    }

public:
    DynamicArray()
    {
        ReAllocate(2);
    }

    ~DynamicArray()
    {
        delete[] m_Data;
        std::cout << "Dyn Array destroyed\n";
    }

    explicit DynamicArray(const size_t& size)
    {
        ReAllocate(size);
    }

    size_t Size() const
    {
        return m_Size;
    }

    size_t Capacity()
    {
        return m_Capacity;
    }

    void PushBack (const type& data)
    {
        if ( m_Size >= m_Capacity)
            ReAllocate(m_Capacity * 2);
        m_Data[m_Size++] = std::move(data);
        std::cout << "l value pushed into array.\n" ;

    }

    void PushBack ( type&& data)
    {
        if ( m_Size >= m_Capacity)
            ReAllocate(m_Capacity * 2);
        m_Data[m_Size++] = std::move(data);
        std::cout << "r value pushed into array.\n" ;
    }

    void EmplaceBack(const type& data)
    {

    }

    void PopBack ()
    {
        m_Size--;
        std::cout << "last value popped off.\n" ;

    }

    void Clear ()
    {

    }

    const type& At(const int& index) const
    {
        return m_Data[index];
    }

    type& At(const int& index)
    {
        return m_Data[index];
    }


    type& operator[](const size_t& index)
    {
            return m_Data[index];
    }

    const type& operator[](size_t index) const
    {
        return m_Data[index];
    }

};
#endif //SRC_VECTOR_H
