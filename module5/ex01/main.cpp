#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.decrementGrade();
        std::cout << bob << std::endl;

        Bureaucrat alice("Alice", 50);
        Form formA("FormA", 30, 20);

        std::cout << formA << std::endl;

        alice.signForm(formA);
        bob.signForm(formA);

        std::cout << formA << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat charlie("Charlie", 151);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form formB("FormB", 0, 20); // This will throw an exception
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
