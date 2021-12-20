/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:34:11 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/20 09:21:09 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <Animal.hpp>

class Cat : public Animal {
	
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat& src);
		virtual ~Cat();
		Cat& operator=(const Cat& rhs);
	
		virtual void makeSound() const;
};
