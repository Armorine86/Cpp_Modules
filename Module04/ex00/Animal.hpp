/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:53:12 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/20 09:21:36 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

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
