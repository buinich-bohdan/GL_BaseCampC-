#pragma once
#include <string>
#include <iostream>
enum _type {
    YYYYMMDD,
    DDMMYYYY,
    DD_MM_YYYY
};

class Date {
private:
    int day;
    int month;
    int year;
    _type type;
    int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool isLeapYear(int);

public:
    Date();
    Date(std::string const&);
    void add(int);
    void sub(int);
    friend int operator-(Date const&, Date const&);
    friend std::istream& operator>>(std::istream&, Date&);
    friend std::ostream& operator<<(std::ostream&, Date const&);
};

int operator-(Date const&, Date const&);
std::istream& operator>>(std::istream&, Date&);
std::ostream& operator<<(std::ostream&, Date const&);