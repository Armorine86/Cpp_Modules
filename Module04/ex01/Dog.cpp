/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:39:17 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/31 13:58:10 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

#include "Brain.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog Subclass Constructor called [DEFAULT]" << std::endl;
}

Dog::Dog(std::string type) : Animal(), brain(new Brain())
{
    this->type = type;
    std::cout << "Dog Subclass Overload Constructor called [CONSTRUCTOR]" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(), brain(new Brain())
{
     for (size_t i = 0; i < N_IDEAS; i++)
        brain->setIdea(i, src.brain->getIdea(i));
    type = src.type;
    std::cout << "Dog Subclass Copy Constructor Called [COPY]" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
    delete brain;
}

Dog& Dog::operator=(const Dog& rhs)
{
    if (this != &rhs) {
        for (size_t i = 0; i < N_IDEAS; i++) {
            brain->setIdea(i, rhs.brain->getIdea(i));
        }
        type = rhs.type;
        return (*this);
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "[DOG] Wouf Wouf ! " << std::endl;
}

Brain& Dog::getBrain() const
{
    return (*this->brain);
}
