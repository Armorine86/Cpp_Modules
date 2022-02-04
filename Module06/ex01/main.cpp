/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 09:39:34 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/04 09:17:13 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include <iostream>

#include "Data.hpp"
#include "colors.hpp"

//  reinterpret_cast<T>(ptr) *

// 	https://www.geeksforgeeks.org/reinterpret_cast-in-c-type-casting-operators/#:~:text=reinterpret_cast%20is%20a%20type%20of,pointer%20is%20same%20or%20not.

//	https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used

// 	https://en.cppreference.com/w/cpp/language/reinterpret_cast

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

int main(void)
{
    Data* obj = new Data();
    int size = sizeof(obj);

    std::cout << GREEN << "\nSize of Data [obj]: " << END << size << " bytes "
              << "(" << size * 8 << " bits)" << std::endl;

    std::cout << GREEN << "\nObject address [obj]: " << END << obj << std::endl;

    uintptr_t uptr = serialize(obj);
    std::cout << GREEN << "\nSerialized Object [obj]: " << END << uptr << std::endl;

    obj = deserialize(uptr);
    size = sizeof(uptr);

    std::cout << GREEN << "\nSize of uintptr_t [uptr]: " << END << size << " bytes "
              << "(" << size * 8 << " bits)" << std::endl;

    std::cout << GREEN << "\nDeserialized uintptr_t [uptr]: " << END << obj << std::endl;
}
