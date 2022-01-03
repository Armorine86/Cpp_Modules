/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 08:14:22 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/03 10:12:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <cstddef>

template<class T>
class Array {

public:
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	Array& operator=(const T& rhs);
	~Array() { delete[] array; }
	T& operator[](unsigned int i);

	unsigned int getSize();
	
private:
	T *array;
	unsigned int size;
};

template<class T>
Array<T>::Array() : array(NULL), size(0) {}

template<class T>
Array<T>::Array(unsigned int n) 
{
	size = n;
	array = new T[n]();
}

template<class T>
Array<T>::Array(const Array &src) 
{
	size = src.size;
	
	array = new T[size]();
	for (unsigned int i = 0; i < size; i++)
		array[i] = src.array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const T &rhs)
{
	if (this == &rhs)
		return *this;
	
	size = rhs.size;
	
	if (array != NULL)
		delete[] array;
	
	for (int i = 0; i < size; i++)
		array[i] = rhs.array[i];
}

template<class T>
unsigned int Array<T>::getSize() 
{
	return size;
}

template<class T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= size || i < 0)
		throw std::exception();
	return array[i];
}
