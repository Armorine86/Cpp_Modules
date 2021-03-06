/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 07:57:48 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/03 09:44:25 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

#define DFLT_GRADE 130
#define FORM_HIGHEST 1
#define FORM_LOWEST 150

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool isSigned;
    const int SignGrade;
    const int ExecGrade;

public:
    Form();
    Form(const std::string& name, bool isSigned, int signgrade, int execgrade);
    Form(const Form& src);
    virtual ~Form();
    Form& operator=(const Form& rhs);

    std::string getFormName() const;
    bool isFormSigned() const;
    int getReqSignGrade() const;
    int getReqExecGrade() const;

    void beSigned(const Bureaucrat& b);
    void checkGrade();

    virtual void execute(Bureaucrat const& executor) const = 0;

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
    class FormAlreadySignedException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    class FormIsNotSignedException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, Form& f);
