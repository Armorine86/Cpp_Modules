/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:57:19 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/01 09:30:18 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

#include "Brain.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
    type = "Cat";
    std::cout << "Cat Subclass Constructor Called [DEFAULT]" << std::endl;
}

Cat::Cat(std::string type) : Animal(), brain(new Brain())
{
    this->type = type;
    std::cout << "Cat Subclass Overload Constructor Called [OVERLOARD]" << std::endl;
}

Cat::Cat(const Cat& src): Animal(), brain(new Brain())
{
    std::cout << "Cat Subclass Copy Constructor Called [COPY]" << std::endl;
    
    // Deep copy, each object will point at their own brain location in memory
    *this = src;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
    delete brain;
}

Cat& Cat::operator=(const Cat& rhs)
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

void Cat::makeSound() const
{
    std::cout << "[CAT] Meow Meow !" << std::endl;
}

Brain& Cat::getBrain() const
{
    return *brain;
}
