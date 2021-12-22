/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:57:25 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/22 10:57:42 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	int reqSignGrade;
	int reqExecGrade;
	
public:
	PresidentialPardonForm();
	PresidentialPardonForm(int signGrade, int execGrade);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs);
	
	virtual void execute(Bureaucrat const & executor) const;
};
