/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:26:42 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/28 14:39:53 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define N_TYPES 4

class Intern {

public:
	Intern();
	Intern(const Intern &src);
	virtual ~Intern();
	Intern& operator=(const Intern &rhs);

	Form* makeForm(const std::string &formName, const std::string &target);
	
	enum {
		shrubbery,
		robo,
		pardon,
		noname
	};
	
	class NoNameException : public std::exception
	{
	public:
		virtual const char* what() const throw();	
	};

private:
	int type;
};
