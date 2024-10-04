#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request", 72, 45), target_(target)
{
    std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Drilling noises..." << std::endl;
    if (std::rand() % 2)
    {
        std::cout << target_ << " has been robotomized successfully." << std::endl;
    }
    else
    {
        std::cout << "The robotomy failed on " << target_ << "." << std::endl;
    }
}
