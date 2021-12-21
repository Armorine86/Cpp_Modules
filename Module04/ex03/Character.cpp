/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:30:45 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 10:53:13 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include "AMateria.hpp"

Character::Character() : name()
{
    for (int i = 0; i < INV_SPACE; i++)
        inventory[i] = NULL;
}

Character::Character(const std::string &name) : name(name)
{
    for (int i = 0; i < INV_SPACE; i++)
        inventory[i] = NULL;
}

Character::Character(const Character &src)
{
    *this = src;
}

Character::~Character()
{
    for (int i = 0; i < INV_SPACE; i++)
        delete inventory[i];
}

Character &Character::operator=(const Character &rhs)
{
    if (this != &rhs) {
        name = rhs.name;
        for (int i = 0; i < INV_SPACE; i++)
            delete inventory[i];
        for (int i = 0; i < INV_SPACE; i++) {
            if (rhs.inventory[i])
                inventory[i] = rhs.inventory[i];
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < INV_SPACE; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3)
        return;
    if (inventory[idx])
        inventory[idx]->use(target);
}
