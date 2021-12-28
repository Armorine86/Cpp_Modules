/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:13:46 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/28 09:39:12 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: Form(PRES_DFLT, false, PRES_SIGN, PRES_EXEC), target(PRES_DFLT)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form(PRES_DFLT, false, PRES_SIGN, PRES_EXEC), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: target(src.target)
{}

PresidentialPardonForm::~PresidentialPardonForm() 
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
		return *this;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!isFormSigned())
		throw Form::FormIsNotSignedException();
	else if (executor.getExecGrade() > getReqExecGrade())
		throw Bureaucrat::GradeTooLowException();
	
	std::cout << "<" << target << "> has been pardoned by Zafod Beeblebrox." << std::endl;
}
