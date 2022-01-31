/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:00:25 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/31 14:38:06 by mmondell         ###   ########.fr       */
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
        std::cout << "\nDEEP COPY TESTS\n";
        std::cout << "========================================" << std::endl;

        Cat *cat1 = new Cat();
    
        std::cout << std::endl;
        cat1->getBrain().setIdea(10, "LET ME OUT KAREN !");
        std::cout << "[CAT 1] " << cat1->getBrain().getIdea(10) << std::endl;
        std::cout << std::endl;
    
        Cat cat2(*cat1);
    
        std::cout << std::endl;
        std::cout << "[CAT 2] " << cat2.getBrain().getIdea(10) << std::endl;
        std::cout << std::endl;

        delete cat1;

        std::cout << std::endl;
        std::cout << "[CAT 2] " << cat2.getBrain().getIdea(10) << std::endl;
        std::cout << std::endl;

        Cat cat3;

        cat3 = cat2;

        std::cout << std::endl;
        std::cout << "[CAT 3] " << cat3.getBrain().getIdea(10) << std::endl;
        std::cout << std::endl;

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
        cat->getBrain().setIdea(10, "Obey me Hooman!");
        dog->getBrain().setIdea(25, "Where's my bone?");

        std::cout << "[" << cat->getType() << "]" << cat->getBrain().getIdea(10) << std::endl;
        std::cout << "[" << dog->getType() << "]" << dog->getBrain().getIdea(25) << std::endl;

        std::cout << std::endl;

        delete cat;
        std::cout << std::endl;
        delete dog;
    }

    {
        std::cout << "\nARRAY TESTS\n";
        std::cout << "========================================" << std::endl;
        Animal *animals[ARR_SIZE];

        //* Fill Array half dogs, half cats
        for (size_t i = 0; i < ARR_SIZE; i++) {
            if (i < ARR_SIZE / 2) {
                animals[i] = new Cat();
                std::cout << std::endl;
            } else {
                animals[i] = new Dog();
                std::cout << std::endl;
            }
        }

        std::cout << std::endl;

        for (size_t i = 0; i < ARR_SIZE; i++) {
            std::cout << "Index [" << i << "] ";
            std::cout << animals[i]->getType() << std::endl;
            animals[i]->makeSound();
            std::cout << std::endl;
        }

        std::cout << std::endl;

        for (size_t i = 0; i < ARR_SIZE; i++) {
            delete animals[i];
            std::cout << std::endl;
        }
    }
}
