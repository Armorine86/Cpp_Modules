/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:45:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/22 10:54:36 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	int reqSignGrade;
	int reqExecGrade;
	
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(int signGrade, int execGrade);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
	
	virtual void execute(Bureaucrat const & executor) const;
};
