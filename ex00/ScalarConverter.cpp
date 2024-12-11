#include "ScalarConverter.hpp"

#include <iostream> // cout, endl
#include <iomanip>  // setprecision, fixed
#include <limits>   // numeric_limits
#include <cstdlib>  // strtod
#include <cmath>    // isnan, isinf

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
  return *this;
}

// strtop: https://cplusplus.com/reference/cstdlib/strtod/
// c_str: https://cplusplus.com/reference/string/string/c_str/
void    ScalarConverter::convert(std::string const &input) {
    double value;

    // Convert string to double
    char *end;
    value = std::strtod(input.c_str(), &end);

    // Check if the conversion was successful
    if (*end != '\0' && input != "nan" && input != "inf" && input != "-inf" && input != "+inf") {
        std::cout << "Error: Invalid literal" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

// staic_cast: https://www.ibm.com/docs/es/i/7.5?topic=expressions-static-cast-operator-c-only
void    ScalarConverter::printChar(double value) {
    std::cout << "char: ";

    if (value < 0 || value > 127 || std::isnan(value)) {
        std::cout << "imposible" << std::endl;
    }
    else if (!std::isprint(static_cast<int>(value))) {
        std::cout << "Non displayable" << std::endl;
    }
    else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
}

// numeric_limits: https://cplusplus.com/reference/limits/numeric_limits/
void    ScalarConverter::printInt(double value) {
    std::cout << "int: ";

    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value)) {
        std::cout << "imposible" << std::endl;
    }
    else {
        std::cout << static_cast<int>(value) << std::endl;
    }
}

// setprecision: https://cplusplus.com/reference/iomanip/setprecision/
// fixed: https://cplusplus.com/reference/iomanip/fixed/
void    ScalarConverter::printFloat(double value) {
    std::cout << "float: ";

    if (std::isinf(value) || std::isnan(value)) {
        std::cout << value << "f" << std::endl;
    }
    else {
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    }
}

void    ScalarConverter::printDouble(double value) {
    std::cout << "double: ";

    if (std::isinf(value) || std::isnan(value)) {
        std::cout << value << std::endl;
    }
    else {
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
    }
}
