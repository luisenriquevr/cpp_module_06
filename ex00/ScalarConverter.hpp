#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>   // std::string

class ScalarConverter {
  public:
    static void convert(std::string const &input);

  private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);

    static void printChar(double c);
    static void printInt(double i);
    static void printFloat(double f);
    static void printDouble(double d);
};

#endif
