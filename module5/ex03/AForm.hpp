#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

class AForm
{
public:
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Form grade too high!";
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Form grade too low!";
        }
    };

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Form not signed!";
        }
    };

    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    virtual ~AForm();

    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

private:
    const std::string name_;
    bool isSigned_;
    const int gradeToSign_;
    const int gradeToExecute_;

    AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif // AFORM_HPP
