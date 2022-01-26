/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:53:12 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/26 10:29:40 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "colors.hpp"


class Animal
{
protected:
    std::string type;

public:
    Animal();
    Animal(std::string type);
    Animal(const Animal& src);
    virtual ~Animal();
    Animal& operator=(const Animal& rhs);

    std::string  getType() const;
    virtual void makeSound() const;
};
