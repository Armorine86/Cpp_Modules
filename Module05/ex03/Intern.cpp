#include "Intern.hpp"

Intern::Intern() : type(0) {}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &rhs)
{
    if (this != &rhs) {
        *this = rhs;
        return *this;
    }
    return *this;
}

Form *Intern::makeForm(const std::string &formName, const std::string &target)
{
    Form *form(NULL);

    std::string formType[N_TYPES] = { "shrubbery request", "robotomy request", "pardon request" };

    for (int i = 0; i < N_TYPES; i++) {
        if (formName == formType[i]) {
            this->type = i;
            break;
        }
    }

    switch (type) {
        case Intern::shrubbery:
            form = new ShrubberyCreationForm(target);
            break;
        case Intern::robo:
            form = new RobotomyRequestForm(target);
            break;
        case Intern::pardon:
            form = new PresidentialPardonForm(target);
            break;
        case Intern::noname:
            delete form;
            throw Intern::NoNameException();
            break;
    }

    std::cout << "Intern creates <" << formName << "> form." << std::endl;

    return form;
}

const char *Intern::NoNameException::what() const throw()
{
    return "Error: Form requires a name";
}
