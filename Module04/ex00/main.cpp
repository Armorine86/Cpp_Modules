/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:00:25 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/20 09:22:40 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		std::cout << "=========================================" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << std::endl;

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		
		std::cout << std::endl;

		//* Virtual
		i->makeSound(); //* will output the cat sound!
		j->makeSound(); //* will output the dog sound!
		meta->makeSound();
		
		std::cout << std::endl;

		delete (meta);
		delete (j);
		delete (i);
	}
	
	std::cout << "=========================================" << std::endl;
	std::cout << "\n=========================================" << std::endl;
	
	{
		WrongAnimal *wronganimal = new WrongAnimal();
		WrongAnimal *wrongcat = new WrongCat();

		std::cout << std::endl;
		
		std::cout << wronganimal->getType() << std::endl;
		std::cout << wrongcat->getType() << std::endl;
		
		std::cout << std::endl;
		
		//* Not Virtual
		wronganimal->makeSound(); //* They will both output the Wrong Animal Noises
		wrongcat->makeSound();

		std::cout << std::endl;

		delete (wrongcat);
		delete (wronganimal);
	}
	std::cout << "=========================================" << std::endl;

}
