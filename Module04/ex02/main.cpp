/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:00:25 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/20 19:56:51 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define ARR_SIZE 6

int main(void)
{
    {
        //* Cats and Dogs get their brains
        std::cout << "\nBRAIN TESTS\n";
        std::cout << "========================================" << std::endl;
        //* Animal *animal = new Animal();
        //* This cannot be instantiated because of a pure virtual function
        std::cout << std::endl;
        Animal *cat1 = new Cat();
        std::cout << std::endl;
        Animal *dog1 = new Dog();

        std::cout << std::endl;

        //* delete animal;
        std::cout << std::endl;
        delete cat1;
        std::cout << std::endl;
        delete dog1;
        std::cout << "========================================" << std::endl;
    }

    {
        //* Idea setting / Getting tests
        std::cout << "\nIDEAS TESTS\n";
        std::cout << "========================================" << std::endl;

        Cat *cat = new Cat();
        std::cout << std::endl;
        Dog *dog = new Dog();

        std::cout << std::endl;

        std::cout << "Inside the Brains! :\n";
        std::cout << "====================" << std::endl;
        cat->getBrain().setIdea(10, "Obey me Hooman!\n");
        dog->getBrain().setIdea(25, "Where's my bone?\n");

        std::cout << "[" << cat->getType() << "]" << cat->getBrain().getIdea(10);
        std::cout << "[" << dog->getType() << "]" << dog->getBrain().getIdea(25);

        std::cout << std::endl;

        delete cat;
        std::cout << std::endl;
        delete dog;
    }

    {
        int32_t i = 0;

        std::cout << "\nARRAY TESTS\n";
        std::cout << "========================================" << std::endl;
        Animal *animals[ARR_SIZE];

        //* Fill Array half dogs, half cats
        for (; i < ARR_SIZE; i++) {
            if (i < ARR_SIZE / 2) {
                animals[i] = new Cat();
                std::cout << std::endl;
            } else {
                animals[i] = new Dog();
                std::cout << std::endl;
            }
        }

        std::cout << std::endl;

        for (i = 0; i < ARR_SIZE; i++) {
            std::cout << "Index [" << i << "] ";
            std::cout << animals[i]->getType() << std::endl;
            animals[i]->makeSound();
            std::cout << std::endl;
        }

        std::cout << std::endl;

        for (i = 0; i < ARR_SIZE; i++) {
            delete animals[i];
            std::cout << std::endl;
        }
    }
}
