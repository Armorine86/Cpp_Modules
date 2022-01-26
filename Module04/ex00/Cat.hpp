/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:34:11 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/26 10:29:21 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "colors.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(std::string type);
    Cat(const Cat& src);
    virtual ~Cat();
    Cat& operator=(const Cat& rhs);

    virtual void makeSound() const;
};
