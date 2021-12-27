/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:13:42 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/22 16:53:46 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "colors.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form(SHRUB_NAME, SHRUB_SIGN, SHRUB_EXEC)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: Form(src.getFormName(), src.getReqSignGrade(), src.getReqExecGrade())
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
	: Form(SHRUB_NAME, SHRUB_SIGN, SHRUB_EXEC), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) 
{
	if (this != &rhs)
	{
		*this = rhs;
		return *this;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getExecGrade() > getReqExecGrade())
		throw Bureaucrat::GradeTooLowException();
	
	std::ofstream file((getTarget() + "_shrubbery").c_str());

	if (file.is_open())
	{
		file	<< "                                   ░░░░░░░░▒▒░░░░░░▒▒░░\n"
				<< "                             ░░░░▒▒░░░░░░░░░░░░░░░░▒▒░░░░░░\n"
				<< "                            ░░░░░░░░░░▒▒▒▒▒▒░░░░░░░░░░▒▒░░░░░░░░\n"
				<< "                          ▒▒░░░░░░░░░░▒▒▒▒▒▒░░░░░░░░░░░░▒▒░░░░░░░░░░\n"
				<< "                          ▒▒░░░░░░░░░░▒▒▒▒▒▒░░░░░░░░▒▒▓▓▒▒░░░░░░░░▒▒░░\n"
				<< "                        ▒▒░░░░░░░░░░░░▒▒▓▓▒▒▒▒▒▒░░░░▒▒▒▒▒▒░░░░▒▒░░░░▒▒\n"
				<< "                  ░░▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒▒░░░░░░▒▒▒▒░░░░▒▒░░░░░░░░▒▒░░▒▒\n"
				<< "                ▒▒▒▒░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░▒▒▒▒░░▒▒▒▒░░░░▒▒░░\n"
				<< "              ░░▒▒▒▒░░░░░░▒▒▒▒▒▒▒▒▒▒░░░░▒▒░░░░░░░░░░░░░░░░▒▒▒▒░░░░░░░░░░▒▒\n"
				<< "          ░░▒▒▒▒░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒░░░░░░░░▒▒░░░░░░░░▒▒▒▒▒▒░░▒▒░░▒▒▒▒▒▒▒▒\n"
				<< "          ░░░░░░▒▒░░░░░░░░▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒░░▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"
				<< "    ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▓▓▒▒░░░░▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"
				<< "  ░░░░░░░░░░▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓░░░░▒▒▒▒▒▒▒▒██░░▒▒░░▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒\n"
				<< "  ░░▒▒░░░░░░▒▒▒▒▒▒▒▒▒▒▓▓░░▓▓▒▒▓▓▓▓▒▒░░▒▒▓▓▓▓▒▒░░▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒░░▒▒▒▒▒▒░░\n"
				<< "  ░░░░░░░░░░░░▓▓▒▒▒▒▒▒░░▒▒▓▓▓▓▒▒▓▓██▓▓████▓▓▓▓▒▒▓▓▓▓▒▒▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░▒▒░░\n"
				<< "  ░░▒▒░░░░░░▒▒▒▒▓▓▒▒▓▓░░░░▒▒▒▒██▓▓▓▓██████▒▒██▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒░░░░▒▒░░░░░░▒▒▒▒\n"
				<< "      ▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▓▓██▒▒██████▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▒▒▒▒▒▒░░░░░░░░░░░░\n"
				<< "        ▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓████▓▓░░░░▓▓  ▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒░░░░░░░░▒▒░░▒▒\n"
				<< "          ▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▓▓██░░▒▒▓▓      ▓▓▓▓  ▓▓▓▓▓▓▓▓▒▒░░░░▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒░░░░▒▒▒▒▒▒\n"
				<< "          ░░░░    ▓▓▒▒  ▒▒▓▓▓▓    ▒▒▒▒▒▒▓▓▒▒▓▓░░▒▒▓▓░░      ▓▓▓▓▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░\n"
				<< "                          ▓▓▓▓      ▓▓▒▒▓▓▓▓▓▓▒▒▓▓▓▓      ░░▓▓          ░░▒▒░░▒▒░░░░░░\n"
				<< "                          ▒▒▒▒▓▓▓▓▒▒██▒▒▓▓▓▓▒▒▓▓▓▓    ▓▓▒▒▓▓\n"
				<< "                              ▓▓▓▓▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓░░\n"
				<< "                                ▓▓▓▓▒▒▓▓▒▒▒▒██████▓▓\n"
				<< "                                  ▒▒▓▓▓▓▓▓▓▓▓▓▒▒░░\n"
				<< "                                ▒▒▒▒▓▓▒▒▓▓▓▓▓▓\n"
				<< "                                ▒▒▒▒▓▓▒▒▓▓▓▓\n"
				<< "                                ▒▒▒▒▓▓▒▒▓▓▓▓\n"
				<< "                                ▒▒▒▒▒▒▓▓▓▓\n"
				<< "                                ▒▒▓▓▒▒▓▓▓▓\n"
				<< "                              ▓▓▒▒▒▒▒▒▓▓▓▓\n"
				<< "                              ▓▓▒▒▒▒▒▒▓▓▓▓▒▒\n"
				<< "                            ▒▒▒▒▓▓▒▒▒▒▓▓▓▓▒▒\n"
				<< "                          ▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒░░  ░░\n"
				<< "                ░░▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▓▓▓▓▒▒██▓▓░░▒▒  ░░░░\n"
				<< "        ░░▒▒▓▓▒▒▒▒▒▒▓▓▒▒▒▒▓▓▒▒▓▓▒▒▓▓▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▒▒▒▒░░\n"
				<< "    ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▓▓▒▒▓▓▓▓▒▒▒▒▓▓▒▒▓▓▒▒▒▒▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒\n"
				<< "  ░░▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒░░\n"
				<< "  ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒░░░░░░▒▒▒▒▒▒\n"
				<< "  ░░▒▒▒▒▒▒▒▒▒▒░░▒▒░░▒▒▒▒▓▓▓▓▒▒▒▒░░░░░░▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓░░░░\n"
				<< "    ▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒  ▓▓  ░░░░░░\n"
				<< "            ░░▒▒▒▒▒▒░░    ▓▓▓▓░░▓▓▒▒▒▒▒▒▒▒\n";
	}
	file.close();
   std::cout << "<" << executor.getName() << "> successfully executed form: <"
              << getFormName() << ">" << std::endl; 
}
