/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:39:17 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/02 08:44:22 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"
#include "Brain.hpp"


Dog::Dog() : Animal(), brain(new Brain())
{
    type = "Dog";
    std::cout << "Dog Subclass Constructor called [DEFAULT]" << std::endl;
}

Dog::Dog(std::string type) : Animal(), brain(new Brain())
{
    this->type = type;
    std::cout << "Dog Subclass Overload Constructor called [CONSTRUCTOR]" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(), brain(new Brain())
{
    std::cout << "Dog Subclass Copy Constructor Called [COPY]" << std::endl;
    
    // Here, the overloaded assignation operator is called
    // which will deep copy the object.
    *this = src;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
    delete brain;
}

Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << "Assignation Operator called" << std::endl;
    if (this != &rhs) {
        for (size_t i = 0; i < N_IDEAS; i++) {
            brain->setIdea(i, rhs.brain->getIdea(i));
        }
        type = rhs.type;
        return *this;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "[DOG] Wouf Wouf ! " << std::endl;
}

Brain& Dog::getBrain() const
{
    return *brain;
}
