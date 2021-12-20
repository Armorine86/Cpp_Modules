/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:00:25 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/20 11:26:04 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ARR_SIZE 6

int main(void)
{
	{
		//* Cats and Dogs get their brains
		std::cout << "\nBrain Tests\n";
		std::cout << "========================================" << std::endl;
		Animal *animal = new Animal();
		std::cout << std::endl;
		Animal *cat1 = new Cat();
		std::cout << std::endl;
		Animal *dog1 = new Dog();
		
		std::cout << std::endl;

		delete animal;
		std::cout << std::endl;
		delete cat1; 
		std::cout << std::endl;
		delete dog1;
		std::cout << "========================================" << std::endl;
	}

	{
		int32_t i = 0;
		
		std::cout << "\nArray tests\n";
		std::cout << "========================================" << std::endl;
		Animal *animals[ARR_SIZE];

		//* Fill Array half dogs, half cats
		for (; i < ARR_SIZE; i++)
		{
			if (i < ARR_SIZE / 2)
			{
				animals[i] = new Cat();
				std::cout << std::endl;
			}
			else
			{
				animals[i] = new Dog();
				std::cout << std::endl;
			}
		}
		
		std::cout << std::endl;

		
		
		for (i = 0; i < ARR_SIZE; i++)
		{
			std::cout << "Index [" << i << "] ";
			std::cout << animals[i]->getType() << std::endl;
			animals[i]->makeSound();
		}
		
		std::cout << std::endl;

		for (i = 0; i < ARR_SIZE; i++)
		{
			delete animals[i];
			std::cout << std::endl;
		}
	}
}
