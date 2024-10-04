#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

const std::string &AForm::getName() const
{
    return name_;
}

bool AForm::isSigned() const
{
    return isSigned_;
}

int AForm::getGradeToSign() const
{
    return gradeToSign_;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute_;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign_)
        throw GradeTooLowException();
    isSigned_ = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form " << form.getName() << ", requires grade " << form.getGradeToSign()
       << " to sign, grade " << form.getGradeToExecute() << " to execute, signed status: "
       << (form.isSigned() ? "signed" : "not signed");
    return os;
}
