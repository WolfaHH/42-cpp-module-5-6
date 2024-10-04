#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 75);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Alice");
        PresidentialPardonForm pardon("Charlie");

        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);

        bob.signForm(robotomy);
        bob.executeForm(robotomy);

        Bureaucrat alice("Alice", 20);
        alice.signForm(pardon);
        alice.executeForm(pardon);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
