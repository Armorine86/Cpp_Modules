/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 08:14:09 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/07 08:37:33 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.hpp"
#include "colors.hpp"

int main(void)
{
    {
        std::cout << BGREEN << "======================\n";
        std::cout << "|| EMPTY ARRAY TEST ||\n";
        std::cout << "======================\n" << END << std::endl;

        try {
            Array<int> arr;
            std::cout << arr[0] << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << BRED << " Array is empty." << END << std::endl;
        }
    }

    std::cout << std::endl;

    {
        std::cout << BGREEN << "=====================\n";
        std::cout << "|| ARRAY INIT TEST ||\n";
        std::cout << "=====================\n" << END << std::endl;

        Array<unsigned int> arr(5);
        for (unsigned int i = 0; i < arr.getSize(); i++)
            arr[i] = i;

        for (unsigned int i = 0; i < arr.getSize(); i++)
            std::cout << arr[i] << " ";

        std::cout << std::endl;
    }

    {
        std::cout << BGREEN << "\n=====================\n";
        std::cout << "|| COPY ARRAY TEST ||\n";
        std::cout << "=====================\n" << END << std::endl;

        Array<char> alphabet(26);

        unsigned int size = alphabet.getSize();

        std::cout << YELLOW << "Original array:\n" << END;
        std::cout << "Array of size: [" << size << "]" << std::endl;

        for (unsigned int i = 0; i < alphabet.getSize(); i++)
            alphabet[i] = static_cast<char>(i) + 'a';

        for (unsigned int i = 0; i < alphabet.getSize(); i++)
            std::cout << alphabet[i] << " ";
        std::cout << std::endl;

        Array<char> arr_cpy(alphabet);

        size = arr_cpy.getSize();

        std::cout << YELLOW << "\nCopy Constructor array:\n" << END;
        std::cout << "Array of size: [" << size << "]" << std::endl;
        for (unsigned int i = 0; i < arr_cpy.getSize(); i++)
            std::cout << arr_cpy[i] << " ";
        std::cout << std::endl;

        Array<char> copy;
        copy = alphabet;

        std::cout << YELLOW << "\nAssignation Copy array:\n" << END;
        std::cout << "Array of size: [" << size << "]" << std::endl;
        for (unsigned int i = 0; i < copy.getSize(); i++)
            std::cout << copy[i] << " ";
        std::cout << std::endl;
    }

    {
        std::cout << BGREEN << "\n========================\n";
        std::cout << "|| INVALID INDEX TEST ||\n";
        std::cout << "========================\n" << END << std::endl;

        Array<unsigned int> arr(5);

        for (unsigned int i = 0; i < arr.getSize(); i++)
            arr[i] = i;

        try {
            std::cout << arr[6] << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << BRED << " Invalid Index" << END << std::endl;
        }
    }

    std::cout << std::endl;
}
