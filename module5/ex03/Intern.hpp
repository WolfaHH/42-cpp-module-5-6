#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

class Intern
{
public:
    Intern();
    ~Intern();
    
    AForm* makeForm(const std::string &formName, const std::string &target) const;

private:
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);

    static AForm* makeShrubberyCreationForm(const std::string &target);
    static AForm* makeRobotomyRequestForm(const std::string &target);
    static AForm* makePresidentialPardonForm(const std::string &target);

    typedef AForm* (*FormCreator)(const std::string &target);
    struct FormType
    {
        std::string name;
        FormCreator creator;
    };

    static const FormType formTypes[];
};

#endif // INTERN_HPP
