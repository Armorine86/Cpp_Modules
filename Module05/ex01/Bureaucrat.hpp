/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:54:15 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/22 09:22:43 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

#include "Form.hpp"

#define HIGHEST 1
#define LOWEST 150

class Form;

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& src);
    virtual ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& rhs);

    const std::string& getName() const;
    int getGrade() const;

    void rankUp();
    void rankDown();

    //* Exception class
    //* https://en.cppreference.com/w/cpp/error/exception/what
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    void signForm(Form& f);
    void checkGrade();

private:
    const std::string name_;
    int grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
