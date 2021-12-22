/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:26:30 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/22 11:11:25 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
    name("BasicForm"),
    isSigned(false),
    reqSignGrade(DFLT_GRADE),
    reqExecGrade(DFLT_GRADE)
{
    checkGrade();
}

Form::Form(std::string name, int signgrade, int execgrade) :
    name(name),
    isSigned(false),
    reqSignGrade(signgrade),
    reqExecGrade(execgrade)
{
    checkGrade();
}

Form::Form(const Form& src) :
    name(src.name),
    isSigned(src.isSigned),
    reqSignGrade(src.reqSignGrade),
    reqExecGrade(src.reqExecGrade)
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

int Form::getReqSignGrade()
{
    return reqSignGrade;
}

int Form::getReqExecGrade() 
{
    return reqExecGrade;
}

void Form::setSigned()
{
    if (isSigned == true) {
        std::cout << "Form has already been signed!" << std::endl;
        return;
    }
    isSigned = true;
}

void Form::beSigned(Bureaucrat& b)
{
    if (b.getSignGrade() > reqSignGrade)
        GradeTooLowException();
}

void Form::checkGrade()
{
    if (reqSignGrade > FORM_LOWEST)
        throw GradeTooLowException();
    else if (reqSignGrade < FORM_HIGHEST)
        throw GradeTooHighException();
}

std::ostream& operator<<(std::ostream& out, Form& f)
{
    out << "Form: <" << f.getFormName() << "> -- signature grade: [" << f.getReqSignGrade() << "]"
        << std::endl;

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
