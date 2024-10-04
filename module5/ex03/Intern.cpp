#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
    for (int i = 0; i < 3; ++i)
    {
        if (formTypes[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formTypes[i].creator(target);
        }
    }
    std::cerr << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
    return nullptr;
}

AForm* Intern::makeShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

const Intern::FormType Intern::formTypes[] = {
    {"shrubbery creation", &Intern::makeShrubberyCreationForm},
    {"robotomy request", &Intern::makeRobotomyRequestForm},
    {"presidential pardon", &Intern::makePresidentialPardonForm}
};
