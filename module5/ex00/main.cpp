#include "Bureaucrat.hpp"

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

        Bureaucrat alice("Alice", 0); // This will throw an exception
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat charlie("Charlie", 151); // This will also throw an exception
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
