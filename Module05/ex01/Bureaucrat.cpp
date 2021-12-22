/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:14:14 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/22 09:54:52 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("John"), grade(LOWEST)
{
    checkGrade();

    std::cout << "<" << name_ << "> now works for EvilCorp." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name), grade(grade)
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

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::rankUp()
{
    --grade;

    std::cout << name_ << " has ranked UP!" << std::endl;

    checkGrade();
}

void Bureaucrat::rankDown()
{
    ++grade;

    std::cout << "<" << name_ << "> has ranked DOWN!" << std::endl;

    checkGrade();
}

void Bureaucrat::signForm(Form& f)
{
    std::cout << "<" << getName() << "> is signing form: <" << f.getFormName() << ">\n";
    
    if (f.isFormSigned())
    {
        f.setSigned();
        return;
    }
    
    if (grade < f.getReqGrade())
    {
        std::cout << "<" << getName() << "> successfully signs form: " << f.getFormName()
                  << std::endl;
        f.setSigned();
    }
    else
        std::cout << "<" << getName() << "> cannot sign form: <" << f.getFormName()
                  << "> because <" << getName() << ">'s grade: <" << getGrade() << "> is too low..."
                  << std::endl;
}

void Bureaucrat::checkGrade()
{
    if (grade < HIGHEST)
        throw GradeTooHighException();
    else if (grade > LOWEST)
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
        << "grade: [" << bureaucrat.getGrade() << "]" << std::endl;

    return out;
}
