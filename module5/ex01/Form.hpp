#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

class Form
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

    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    ~Form();

    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);

private:
    const std::string name_;
    bool isSigned_;
    const int gradeToSign_;
    const int gradeToExecute_;

    Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif // FORM_HPP
