/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:40:55 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 09:46:32 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
    std::string type;  //* Name in lowercase "ice"

public:
    Ice();
    Ice(const Ice &src);
    virtual ~Ice();
    Ice &operator=(const Ice &rhs);

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};
