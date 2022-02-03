/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:26:30 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/03 09:59:55 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
    name("BasicForm"),
    isSigned(false),
    SignGrade(SIGN_GRADE),
    ExecGrade(EXEC_GRADE)
{
    checkGrade();
}

Form::Form(std::string name, const int sign_grade, const int exec_grade) :
    name(name),
    isSigned(false),
    SignGrade(sign_grade),
    ExecGrade(exec_grade)
{
    checkGrade();
}

Form::Form(const Form& src) :
    name(src.name),
    isSigned(src.isSigned),
    SignGrade(src.SignGrade),
    ExecGrade(src.ExecGrade)
{
    checkGrade();
}

Form::~Form() {}

Form& Form::operator=(const Form& rhs)
{
    if (this != &rhs) {
        *this = rhs;
        return *this;
    }
    return *this;
}

std::string Form::getFormName()
{
    return name;
}

bool Form::isFormSigned()
{
    return isSigned;
}

int Form::getSignGrade()
{
    return SignGrade;
}

int Form::getExecGrade() 
{
    return ExecGrade;
}

void Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > SignGrade || b.getGrade() > ExecGrade)
        throw Form::GradeTooLowException();
    isSigned = true;
}

void Form::checkGrade()
{
    if (SignGrade > FORM_LOWEST)
        throw GradeTooLowException();
    else if (SignGrade < FORM_HIGHEST)
        throw GradeTooHighException();
}

std::ostream& operator<<(std::ostream& out, Form& f)
{
    out << "Form: <" << f.getFormName()
        << "> -- signature grade: [" << f.getSignGrade() << "]"
        << " execution grade: [" << f.getExecGrade() << "]" << std::endl;

    return out;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "\nGrade is Too High [FORM]";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "\nGrade is Too Low [FORM]";
}
