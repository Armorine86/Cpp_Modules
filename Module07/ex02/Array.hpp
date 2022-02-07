/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 08:14:22 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/07 08:15:34 by mmondell         ###   ########.fr       */
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
    Array() : size(0), array(NULL) {}
    Array(unsigned int n) : size(n), array(new T[n]()) {}
    Array(const Array& src) : size(src.size), array(new T[size]())
    {
        for (unsigned int i = 0; i < size; i++)
            array[i] = src.array[i];
    }
    ~Array() {delete[] array;};

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

    unsigned int getSize() {return size;}

private:
    unsigned int size;
    T* array;
};
