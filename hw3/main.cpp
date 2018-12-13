#include <iostream>
#include "date.hpp"

int main(int argc, char const* argv[])
{
    Date type1("1997.05.21");
    std::cout << "YYYY.MM.DD " << type1 << std::endl;
    Date type2("20.10.1999");
    std::cout << "DD.MM.YYYY " << type2 << std::endl;
    Date type3("10-05-1997");
    std::cout << "DD-MM-YYYY " << type3 << std::endl;
    Date type4;
    std::cin >> type4;
    std::cout << "DD.MM.YYYY " << type4 << std::endl;

    type3.add(2);
    std::cout << "add 2 " << type3 << std::endl;
    type3.sub(-2);
    std::cout << "sub 2 " << type3 << std::endl;

    std::cout << "Operator - " << type1 - type3 << std::endl;

    return 0;
}