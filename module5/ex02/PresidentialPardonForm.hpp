#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm(const std::string &target);
    virtual ~PresidentialPardonForm();

    virtual void execute(Bureaucrat const &executor) const;

private:
    const std::string target_;

    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
};

#endif // PRESIDENTIALPARDONFORM_HPP
