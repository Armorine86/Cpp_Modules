/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:51:19 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 13:28:58 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <stdint.h>

#include <iostream>

Brain::Brain()
{
    int32_t i = 0;

    for (; i < N_IDEAS; i++)
        ideas[i] = " ";

    std::cout << "This brain is filled with ideas!" << std::endl;
}

Brain::Brain(const Brain& src)
{
    *this = src;
}

Brain::~Brain()
{
    std::cout << "Brain Destroyed" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
    if (this != &rhs) {
        *this = rhs;
        return (*this);
    }
    return (*this);
}

void Brain::setIdea(int32_t index, std::string idea)
{
    if (index < 0 || index > N_IDEAS - 1) {
        std::cout << "Outside Brain Space!\n";
        idea = " ";
        return;
    }
    this->ideas[index] = idea;
}

std::string Brain::getIdea(int32_t index)
{
    if (index < 0 || index > N_IDEAS - 1) {
        std::cout << "Outside Brain Space!\n";
        return " ";
    }
    return (ideas[index]);
}
