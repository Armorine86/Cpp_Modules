/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 08:53:54 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 09:52:46 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AMateria;

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}

    //* MUST copy the materia passed as parameter
    //* store in memory to be cloned later
    virtual void learnMateria(AMateria *) = 0;

    //* returns a new materia which is a copy previously learned by the srouce
    //* which type equals the parameter
    //* Return 0 if the type is unknown
    virtual AMateria *createMateria(std::string const &type) = 0;
};
