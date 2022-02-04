/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 08:14:22 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/04 16:23:30 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <cstring>
#include <exception>

template <typename T>
class Array
{
public:
    Array();
    Array(unsigned int n);
    Array(const Array& src);
    ~Array();

    Array& operator=(const Array& rhs)
    {
        delete[] array;

        size = rhs.size;
        array = new T[size]();

        std::memcpy(array, rhs.array, rhs.size * sizeof(T));
        
        return *this;
    }

    T& operator[](size_t i)
    {
        if (i >= size || i < 0)
            throw std::exception();
        return array[i];
    }

    unsigned int getSize();

private:
    unsigned int size;
    T* array;
};

// Default constructor
//-------------------
// array(NULL)
// size(0)
template <typename T>
Array<T>::Array() : size(0), array(NULL)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : size(n), array(new T[n]())
{
}

template <typename T>
Array<T>::Array(const Array& src) : size(src.size), array(new T[size]())
{
    for (unsigned int i = 0; i < size; i++)
        array[i] = src.array[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] array;
}

template <typename T>
unsigned int Array<T>::getSize()
{
    return size;
}
