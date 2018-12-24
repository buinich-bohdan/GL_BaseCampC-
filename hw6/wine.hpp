#pragma once
#include <valarray>
#include <string>
#include <utility> // std::pair, std::make_pair
#include <cstring>
#include <iostream>

// class Wine {
// public:
//     Wine(const char*, int, const int*, const int*);
//     // l - means label, y - number of years, yr[] - years of bottling, bot[] - number of bottles

//     Wine(const char*, int);
//     // l - label, y - number of years, array is created with that size

//     void show();
//     void getBottles();
//     std::string& label();
//     int sum();

// private:
//     using ArrayIntT = std::valarray<int>;
//     using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;
//     std::string name;
//     PairArrayT pair;
//     int year;
// };
    
//private interface
using ArrayIntT = std::valarray<int>;
using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;

class Wine: std::string, PairArrayT {

private:

    int year;

    public:
    Wine(const char*, int, const int*, const int*);
    // l - means label, y - number of years, yr[] - years of bottling, bot[] - number of bottles

    Wine(const char*, int);
    // l - label, y - number of years, array is created with that size

    void show();
    void getBottles();
    const char* label() const;
    int sum();

};