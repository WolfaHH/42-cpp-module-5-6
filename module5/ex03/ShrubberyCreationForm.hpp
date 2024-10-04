#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm(const std::string &target);
    virtual ~ShrubberyCreationForm();

    virtual void execute(Bureaucrat const &executor) const;

private:
    const std::string target_;

    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
};

#endif // SHRUBBERYCREATIONFORM_HPP
