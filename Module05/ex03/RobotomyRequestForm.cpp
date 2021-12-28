/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:13:53 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/28 09:39:30 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: Form(ROBO_DFLT, false, ROBO_SIGN, ROBO_EXEC), target(ROBO_DFLT)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
	: Form(ROBO_DFLT, false, ROBO_SIGN, ROBO_EXEC), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) 
	: target(src.target)
{}

RobotomyRequestForm::~RobotomyRequestForm() 
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) 
{
	if (this != &rhs)
	{
		*this = rhs;
		return *this;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!isFormSigned())
		throw Form::FormIsNotSignedException();
	else if (executor.getExecGrade() > getReqExecGrade())
		throw Bureaucrat::GradeTooLowException();
	
	std::srand(time(NULL)); //* seed
	std::cout << "**DddrRriiizzzZTtt...**  ";
	
	if (std::rand() % 2)
		std::cout << "<" << target << "> has been ROBOTOMIZED!" << std::endl;
	else
		std::cout << "<" << target << ">'s ROBOMATIZATION failed!" << std::endl;
}
