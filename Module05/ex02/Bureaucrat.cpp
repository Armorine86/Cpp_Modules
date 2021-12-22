/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:14:14 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/22 11:32:13 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.hpp"

Bureaucrat::Bureaucrat() : name_("John"), SignGrade(LOWEST), ExecGrade(LOWEST)
{
    checkGrade();

    std::cout << "<" << name_ << "> now works for EvilCorp." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int signgrade, int execgrade) :
    name_(name),
    SignGrade(signgrade),
    ExecGrade(execgrade)
{
    checkGrade();

    std::cout << "<" << name_ << "> now works for EvilCorp." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
    *this = src;

    checkGrade();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "<" << name_ << "> has been fired!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs) {
        *this = rhs;
        return *this;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return name_;
}

int Bureaucrat::getSignGrade() const
{
    return SignGrade;
}

int Bureaucrat::getExecGrade() const
{
    return ExecGrade;
}

void Bureaucrat::rankUp()
{
    --SignGrade;

    std::cout << name_ << " has ranked UP!" << std::endl;

    checkGrade();
}

void Bureaucrat::rankDown()
{
    ++SignGrade;

    std::cout << "<" << name_ << "> has ranked DOWN!" << std::endl;

    checkGrade();
}

void Bureaucrat::signForm(Form& f)
{
    std::cout << "<" << getName() << "> is signing form: <" << f.getFormName() << ">\n";

    if (f.isFormSigned()) {
        f.setSigned();
        return;
    }

    if (SignGrade < f.getReqSignGrade()) {
        std::cout << "<" << getName() << "> successfully signs form: " << f.getFormName()
                  << std::endl;
        f.setSigned();
    } else
        std::cout << "<" << getName() << "> cannot sign form: <" << f.getFormName() << "> because <"
                  << getName() << ">'s sign grade: <" << getSignGrade() << "> is too low..." << std::endl;
}

void Bureaucrat::checkGrade()
{
    if (SignGrade < HIGHEST)
        throw GradeTooHighException();
    else if (SignGrade > LOWEST)
        throw GradeTooLowException();
    
    if (ExecGrade < HIGHEST)
        throw GradeTooHighException();
    else if (ExecGrade > LOWEST)
        throw GradeTooLowException();
}

void Bureaucrat::executeForm(const Form &form) 
{
    if (ExecGrade < form.getReqExecGrade())
        std::cout << "<" << getName() << "> executes <" << form.getFormName() << ">"
                  << std::endl;
    else
        throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "\nGrade is Too High [BUREAUCRAT]";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "\nGrade is Too Low [BUREAUCRAT]";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << "<" << bureaucrat.getName() << "> "
        << "sign grade: [" << bureaucrat.getSignGrade() << "]"
        << "exec grade: [" << bureaucrat.getExecGrade() << "]"
        << std::endl;

    return out;
}
