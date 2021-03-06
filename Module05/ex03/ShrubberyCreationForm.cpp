/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:13:42 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/03 10:14:16 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

#include "colors.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form(SHRUB_NAME, false, SHRUB_SIGN, SHRUB_EXEC) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : Form(src.getFormName(), src.isFormSigned(), src.getReqSignGrade(), src.getReqExecGrade())
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form(SHRUB_NAME, false, SHRUB_SIGN, SHRUB_EXEC), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this != &rhs) {
        *this = rhs;
        return *this;
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getExecGrade() > getReqExecGrade())
        throw Bureaucrat::GradeTooLowException();
    else if (!isFormSigned())
        throw Form::FormIsNotSignedException();

    std::ofstream file((getTarget() + "_shrubbery").c_str());

    if (file.is_open()) {
        file << "                                   ????????????????????????????????????????????????????????????\n"
             << "                             ??????????????????????????????????????????????????????????????????????????????????????????\n"
             << "                            ????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "                          ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "                          ????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "                        ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "                  ????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "                ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "              ????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "          ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "          ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "    ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "  ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "  "
                "????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "  "
                "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????"
                "??????\n"
             << "  "
                "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????"
                "????????????\n"
             << "      "
                "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????"
                "\n"
             << "        ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????  "
                "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "          ??????????????????????????????????????????????????????????????????????????????      ????????????  "
                "????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "          ????????????    ????????????  ??????????????????    ????????????????????????????????????????????????????????????      "
                "????????????????????????????????????????????????????????????????????????????????????\n"
             << "                          ????????????      ????????????????????????????????????????????????      ????????????          "
                "??????????????????????????????????????????\n"
             << "                          ????????????????????????????????????????????????????????????????????????    ??????????????????\n"
             << "                              ????????????????????????????????????????????????????????????????????????????????????\n"
             << "                                ????????????????????????????????????????????????????????????\n"
             << "                                  ????????????????????????????????????????????????\n"
             << "                                ??????????????????????????????????????????\n"
             << "                                ????????????????????????????????????\n"
             << "                                ????????????????????????????????????\n"
             << "                                ??????????????????????????????\n"
             << "                                ??????????????????????????????\n"
             << "                              ????????????????????????????????????\n"
             << "                              ??????????????????????????????????????????\n"
             << "                            ????????????????????????????????????????????????\n"
             << "                          ????????????????????????????????????????????????????????????  ??????\n"
             << "                ??????????????????????????????????????????????????????????????????????????????????????????????????????  ????????????\n"
             << "        ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "    ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "  ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "  ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "  ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n"
             << "    ????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????  ??????  ??????????????????\n"
             << "            ??????????????????????????????    ????????????????????????????????????????????????\n";
    }
    file.close();
    std::cout << "<" << executor.getName() << "> successfully executed form: <" << getFormName()
              << ">" << std::endl;
}
