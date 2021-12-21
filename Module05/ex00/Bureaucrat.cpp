/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:14:14 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 16:33:11 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("John"), grade(LOWEST)
{
    if (grade < HIGHEST)
        throw GradeTooHighException();
    else if (grade > LOWEST)
        throw GradeTooLowException();

    std::cout << "<" << name_ << "> grade: " << grade << " is now working for EvilCorp."
              << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name), grade(grade)
{
    if (grade < HIGHEST)
        throw GradeTooHighException();
    else if (grade > LOWEST)
        throw GradeTooLowException();

    std::cout << "<" << name_ << "> grade: "
              << "[" << grade << "]"
              << " is now working for EvilCorp." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
    *this = src;

    if (grade < HIGHEST)
        throw GradeTooHighException();
    else if (grade > LOWEST)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << name_ << " has been fired!" << std::endl;
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

    if (grade < HIGHEST)
        throw GradeTooHighException();
    else if (grade > LOWEST)
        throw GradeTooLowException();
}

void Bureaucrat::rankDown()
{
    ++grade;

    std::cout << name_ << " has ranked DOWN!" << std::endl;

    if (grade < HIGHEST)
        throw GradeTooHighException();
    else if (grade > LOWEST)
        throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "\nGrade is Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "\nGrade is Too Low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << "<" << bureaucrat.getName() << "> "
        << "grade: [" << bureaucrat.getGrade() << "]" << std::endl;

    return out;
}
