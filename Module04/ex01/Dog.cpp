/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:39:17 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/27 11:14:51 by mmondell         ###   ########.fr       */
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

Dog::Dog(std::string type) : Animal()
{
    this->type = type;
    brain = new Brain();
    std::cout << "Dog Subclass Overload Constructor called [CONSTRUCTOR]" << std::endl;
}

Dog::Dog(const Dog& src)
{
    *this->brain = Brain();
    this->type = src.type;
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
        this->type = rhs.type;
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
