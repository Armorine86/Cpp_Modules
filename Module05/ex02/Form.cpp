/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:26:30 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/31 13:03:49 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include "colors.hpp"

Form::Form()
    : name("BasicForm"), isSigned(false), reqSignGrade(DFLT_GRADE), reqExecGrade(DFLT_GRADE)
{
    checkGrade();
}

Form::Form(const std::string& name, bool isSigned, int signgrade, int execgrade)
    : name(name), isSigned(isSigned), reqSignGrade(signgrade), reqExecGrade(execgrade)
{
    checkGrade();
}

Form::Form(const Form& src)
    : name(src.name),
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

std::string Form::getFormName() const
{
    return name;
}

bool Form::isFormSigned() const
{
    return isSigned;
}

int Form::getReqSignGrade() const
{
    return reqSignGrade;
}

int Form::getReqExecGrade() const
{
    return reqExecGrade;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (isFormSigned())
        throw FormAlreadySignedException();
    if (b.getSignGrade() > reqSignGrade)
        throw GradeTooLowException();

    isSigned = true;
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
    out << "Form: <" << f.getFormName() << "> -- Signature grade: [" << f.getReqSignGrade() << "]" << " Execution grade: [" << f.getReqExecGrade() << "]" << std::endl;

    return out;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is Too High [FORM]";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is Too Low [FORM]";
}

const char* Form::FormAlreadySignedException::what() const throw()
{
    return "the form has already been signed";
}

const char* Form::FormIsNotSignedException::what() const throw()
{
    return "Form is not signed";
}
