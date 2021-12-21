/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 08:56:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 10:15:23 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    MateriaSource(const MateriaSource &src);
    virtual ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &rhs);

    virtual void learnMateria(AMateria *);
    virtual AMateria *createMateria(std::string const &type);

private:
    AMateria *materias[4];
};
