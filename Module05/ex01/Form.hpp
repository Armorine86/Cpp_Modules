/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 07:57:48 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/03 10:01:35 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

#define SIGN_GRADE 130
#define EXEC_GRADE 130
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
    Form(std::string name, const int sign_grade, const int exec_grade);
    Form(const Form& src);
    virtual ~Form();
    Form& operator=(const Form& rhs);

    std::string getFormName();
    bool isFormSigned();
    int getSignGrade();
    int getExecGrade();

    void beSigned(Bureaucrat& b);
    void checkGrade();

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
};

std::ostream& operator<<(std::ostream& out, Form& f);
