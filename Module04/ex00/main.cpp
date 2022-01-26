/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:00:25 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/26 12:34:53 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    {
        std::cout << "=========================================" << std::endl;
        const Animal* meta = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();

        std::cout << std::endl;

        std::cout << dog->getType() << std::endl;
        std::cout << cat->getType() << std::endl;

        std::cout << std::endl;

        //* Virtual
        cat->makeSound();  //* will output the cat sound!
        dog->makeSound();  //* will output the dog sound!
        meta->makeSound();

        std::cout << std::endl;

        delete meta;
        delete dog;
        delete cat;
    }

    std::cout << "=========================================" << std::endl;
    std::cout << "\n=========================================" << std::endl;

    {
        WrongAnimal* wronganimal = new WrongAnimal();
        WrongAnimal* wrongcat = new WrongCat();

        std::cout << std::endl;

        std::cout << wronganimal->getType() << std::endl;
        std::cout << wrongcat->getType() << std::endl;

        std::cout << std::endl;

        //* Not Virtual
        wronganimal->makeSound();  //* They will both output the Wrong Animal Noises
        wrongcat->makeSound();

        std::cout << std::endl;

        delete wronganimal;
        delete wrongcat;
    }
    std::cout << "=========================================" << std::endl;
}
