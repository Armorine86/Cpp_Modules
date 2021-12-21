/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 08:47:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 09:02:14 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

#define INV_SPACE 4

//* Interface subclass MUST implement all of it's Interface functions

class Character : public ICharacter {

	public:
		Character();
		Character(const std::string &name);
		Character(const Character &src);
		virtual ~Character();
		Character& operator=(const Character &rhs);

		virtual std::string const &getNAme() const;
		virtual void equip(AMateria *m); 
		virtual void unequip(AMateria *m);
		virtual void use(int idx, ICharacter &target);

	private:
		std::string name;
		AMateria *inventory[INV_SPACE];
};
