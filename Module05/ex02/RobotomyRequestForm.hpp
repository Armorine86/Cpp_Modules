/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:56:28 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/22 10:57:08 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	int reqSignGrade;
	int reqExecGrade;
	
public:
	RobotomyRequestForm();
	RobotomyRequestForm(int signGrade, int execGrade);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs);
	
	virtual void execute(Bureaucrat const & executor) const;
};
