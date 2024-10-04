#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

const std::string &Form::getName() const
{
    return name_;
}

bool Form::isSigned() const
{
    return isSigned_;
}

int Form::getGradeToSign() const
{
    return gradeToSign_;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute_;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign_)
        throw GradeTooLowException();
    isSigned_ = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form " << form.getName() << ", requires grade " << form.getGradeToSign()
       << " to sign, grade " << form.getGradeToExecute() << " to execute, signed status: "
       << (form.isSigned() ? "signed" : "not signed");
    return os;
}
