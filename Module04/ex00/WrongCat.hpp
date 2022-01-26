/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:40:45 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/26 10:29:25 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"
#include "colors.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const std::string& type);
    WrongCat(const WrongCat& src);
    ~WrongCat();

    WrongCat& operator=(const WrongCat& rhs);

    void makeSound() const;  //* without virtual keyword
};
