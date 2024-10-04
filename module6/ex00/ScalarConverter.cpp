#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal)
{
    if (isPseudoLiteral(literal))
    {
        convertFloat(literal);
        convertDouble(literal);
        return;
    }

    if (isChar(literal))
    {
        convertChar(literal);
    }
    else if (isInt(literal))
    {
        convertInt(literal);
    }
    else if (isFloat(literal))
    {
        convertFloat(literal);
    }
    else if (isDouble(literal))
    {
        convertDouble(literal);
    }
    else
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
    }
}

void ScalarConverter::convertChar(const std::string &literal)
{
    char c = literal[0];

    std::cout << "char: " << c << "\n"
              << "int: " << static_cast<int>(c) << "\n"
              << "float: " << static_cast<float>(c) << ".0f\n"
              << "double: " << static_cast<double>(c) << ".0\n";
}

void ScalarConverter::convertInt(const std::string &literal)
{
    long int value = std::strtol(literal.c_str(), NULL, 10);

    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
        return;
    }

    int intValue = static_cast<int>(value);
    char charValue = static_cast<char>(intValue);

    if (intValue < 32 || intValue > 126)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: " << charValue << "\n";

    std::cout << "int: " << intValue << "\n"
              << "float: " << static_cast<float>(intValue) << ".0f\n"
              << "double: " << static_cast<double>(intValue) << ".0\n";
}

void ScalarConverter::convertFloat(const std::string &literal)
{
    float value = std::strtof(literal.c_str(), NULL);

    if (errno == ERANGE)
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
        return;
    }

    int intValue = static_cast<int>(value);
    char charValue = static_cast<char>(intValue);

    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n";
    }
    else
    {
        if (intValue < 32 || intValue > 126)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: " << charValue << "\n";

        std::cout << "int: " << intValue << "\n";
    }

    std::cout << std::fixed << std::setprecision(1)
              << "float: " << value << "f\n"
              << "double: " << static_cast<double>(value) << "\n";
}

void ScalarConverter::convertDouble(const std::string &literal)
{
    double value = std::strtod(literal.c_str(), NULL);

    if (errno == ERANGE)
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
        return;
    }

    int intValue = static_cast<int>(value);
    char charValue = static_cast<char>(intValue);

    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n";
    }
    else
    {
        if (intValue < 32 || intValue > 126)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: " << charValue << "\n";

        std::cout << "int: " << intValue << "\n";
    }

    std::cout << std::fixed << std::setprecision(1)
              << "float: " << static_cast<float>(value) << "f\n"
              << "double: " << value << "\n";
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal)
{
    return literal == "-inff" || literal == "+inff" || literal == "nanf" || 
           literal == "-inf" || literal == "+inf" || literal == "nan";
}

bool ScalarConverter::isChar(const std::string &literal)
{
    return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string &literal)
{
    char *end;
    long int value = std::strtol(literal.c_str(), &end, 10);
    return *end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    char *end;
    std::strtof(literal.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    char *end;
    std::strtod(literal.c_str(), &end);
    return *end == '\0';
}
