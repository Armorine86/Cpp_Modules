/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 08:47:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 10:53:04 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

#define INV_SPACE 4

//* Interface subclass MUST implement all of it's Interface functions

class Character : public ICharacter
{
public:
    Character();
    Character(const std::string &name);
    Character(const Character &src);
    virtual ~Character();
    Character &operator=(const Character &rhs);

    virtual std::string const &getName() const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);  //* MUST NOT delete materia

    //* use the materia at idx slot and pass target to AMateria::use
    virtual void use(int idx, ICharacter &target);

private:
    std::string name;
    AMateria *inventory[INV_SPACE];
};
