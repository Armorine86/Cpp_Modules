/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 08:05:45 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/28 11:02:47 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "ICharacter.hpp"

//* AMateria is an Abstract Class (aka  ABC)
//* A class is made abstract by declaring at least one function as pure virtual ( = 0)
//* A pure virtual function MUST BE overriden in the subclass. Otherwise you get a compilation error
//* Abstract classes CANNOT be instantiated

class AMateria
{
protected:
    std::string type;

public:
    AMateria();                         //* Default
    AMateria(const AMateria &src);      //* Copy
    AMateria(const std::string &type);  //* Overload
    virtual ~AMateria();                //* Destructor

    AMateria &operator=(const AMateria &rhs);

    std::string const &getType() const;  //* Returns the Materia type
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};
