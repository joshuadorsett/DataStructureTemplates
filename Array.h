//
// Created by Joshua Dorsett on 9/26/20.
//

#ifndef SRC_ARRAY_H
#define SRC_ARRAY_H

#include <cstddef>

template<typename type,  size_t size>
class Array
{
private:
    type m_Data[size];
public:
    constexpr size_t Size() const
    {
        return size;
    }
    type& operator[](int& index)
    {
        return m_Data[index];
    }
    const type& operator[](int& index) const {
        return m_Data[index];
    }
    type& Data()
    {
        return  m_Data;
    }
    const type& Data() const
    {
        return m_Data;
    }
};

#endif //SRC_ARRAY_H
