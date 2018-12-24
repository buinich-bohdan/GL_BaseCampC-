#include "wine.hpp"

// Wine::Wine(const char* l, int y, const int yr[], const int bot[])
//     : name(l)
//     , year(y)
// {
//     pair = std::make_pair((ArrayIntT(yr, y)), (ArrayIntT(bot, y)));
// }

// Wine::Wine(const char* l, int y)
//     : name(l)
//     , year(y)
// {
//     pair = std::make_pair(ArrayIntT(y), ArrayIntT(y));
// }

// void Wine::show()
// {
//     std::cout << "Label : " << name << std::endl;
//     for (int i = 0; i < pair.first.size(); ++i)
//         std::cout << "Year of bottel: " << pair.first[i] << " Count: " << pair.second[i] << std::endl;
// }

// std::string& Wine::label()
// {
//     return name;
// }

// int Wine::sum()
// {
//     int count = 0;
//     for (int i = 0; i < pair.second.size(); ++i)
//         count += pair.second[i];
//     return count;
// }

// void Wine::getBottles()
// {

//     std::valarray<int> array1(pair.second.size());
//     std::valarray<int> array2(pair.second.size());

//     for (int i = 0; i < pair.second.size(); ++i) {
//         std::cout << "Enter year of bottels ";
//         std::cin >> array1[i];
//         std::cout << "Enter count of bottels ";
//         std::cin >> array2[i];
//     }
//     pair = std::make_pair(ArrayIntT(array1), ArrayIntT(array2));
// }




//private interface
Wine::Wine(const char* l, int y)
    : std::string(l)
    , year(y)
{
}

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
    : std::string(l)
    , PairArrayT(ArrayIntT(yr, y), ArrayIntT(bot, y))
    , year(y)
{
}

void Wine::getBottles()
{
    PairArrayT::first.resize(year);
    PairArrayT::second.resize(year);

    for (int i = 0; i < PairArrayT::second.size(); ++i) {
        std::cout << "Enter year of bottels ";
        std::cin >> PairArrayT::first[i];
        std::cout << "Enter count of bottels ";
        std::cin >> PairArrayT::second[i];
    }
}

void Wine::show()
{
    std::cout << "Label : " << std::string::c_str() << std::endl;
    for (int i = 0; i < year; ++i) {
        std::cout << "Year of bottel: " << PairArrayT::first[i] << " Count: " << PairArrayT::second[i] << std::endl;
    }
}

const char* Wine::label() const
{
    return std::string::c_str();
}

int Wine::sum()
{
    return PairArrayT::second.sum();
}