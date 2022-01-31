/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:14:14 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/31 12:50:06 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.hpp"

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
    try {
        if (f.isFormSigned() == true)
        {
            std::cout << "Form <" << f.getFormName() << "> has already been signed!" << std::endl;
            return;
        }
        f.beSigned(*this);
        std::cout << "<" << getName() << "> is signing form: <" << f.getFormName() << ">\n";
    } catch (std::exception &e){
        std::cout << YELLOW << "<" << getName() << "> cannot sign form: <" << f.getFormName() << "> because <"
                  << getName() << ">'s grade: <" << getGrade() << "> is too low..." << END << std::endl;
    }
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
