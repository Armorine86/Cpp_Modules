/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:37:45 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/26 10:29:23 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "colors.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(std::string type);
    Dog(const Dog& src);
    virtual ~Dog();
    Dog& operator=(const Dog& rhs);

    virtual void makeSound() const;
};
