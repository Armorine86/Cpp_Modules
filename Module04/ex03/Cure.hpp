/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:40:55 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 09:46:21 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
    std::string type;  //* Name in lowercase "cure"

public:
    Cure();
    Cure(const Cure &src);
    virtual ~Cure();
    Cure &operator=(const Cure &rhs);

    virtual AMateria *clone() const;  //* Returns a new instance of the real Materia type
    virtual void      use(ICharacter &target);
};
