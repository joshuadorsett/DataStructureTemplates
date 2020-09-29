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
        type* newBlock = (type*)::operator new( newCapacity * sizeof(type));
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
            m_Data[i].~type();
        }
        ::operator delete(m_Data, m_Capacity * sizeof(type));
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
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(type));
        std::cout << "Dyn Array destroyed\n";
    }

    explicit DynamicArray(const size_t& size)
    {
        ReAllocate(size);
    }

    const size_t& Size() const
    {
        return m_Size;
    }

     const size_t& Capacity() const
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

    template<typename ...Args>
    type& EmplaceBack(Args&&...args)
    {
        if (m_Size > m_Capacity)
            ReAllocate(m_Capacity * 2);
        new(m_Data[m_Size]) type(std::forward<Args>(args)...);
        return m_Data[m_Size++];

    }

    void PopBack ()
    {
        if(m_Size > 0)
        {
            m_Size--;
            m_Data[m_Size].~type();
        }
        std::cout << "last value popped off.\n" ;
    }

    void Clear ()
    {
        for(int i = 0; i < m_Size; i++)
            m_Data[i].~type();
        m_Size = 0;
        std::cout << "Dyn Array cleared\n";
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

    bool operator==(const DynamicArray<type>& other) const
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
#endif //SRC_VECTOR_H
