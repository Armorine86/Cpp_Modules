/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 08:14:04 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 08:51:45 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

//* ICharacter is an Interface class
//* Interface have no implementation whatsoever
//* All the functions in the Interface are pure virtual (= 0)
//* The Subclass MUST override / Implement ALL the pure virtual functions of the interface class

//* IMPORTANT: Interfaces can be "Multi-Inherited" as opposed to abstract class

class AMateria;

class ICharacter {

	public:
		virtual ~ICharacter();
		virtual std::string const &getNAme() const = 0;
		virtual void equip(AMateria *m) = 0; 
		virtual void unequip(AMateria *m) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};
