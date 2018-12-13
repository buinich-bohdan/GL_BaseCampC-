#include "date.hpp"
#include <regex>
#include <sstream>
#include <iostream>

Date::Date()
{
    day = 1;
    month = 1;
    year = 1950;
    type = DDMMYYYY;
}
Date::Date(std::string const& _data)
{

    std::stringstream date(_data);
    char delim;

    if (std::regex_match(_data, std::regex("(194[0-9]|199[0-9]|200[0-9]|202[0-9])[.](0[1-9]|1[0-2])[.](0[1-9]|1[0-9]|2[0-9]|3[0-1])\\b"))) {
        date >> year >> delim >> month >> delim >> day;
        type = YYYYMMDD;
    }

    else if (std::regex_match(_data, std::regex("(0[1-9]|1[0-9]|2[0-9]|3[0-1])[.](0[1-9]|1[0-2])[.](194[0-9]|199[0-9]|200[0-9]|202[0-9])\\b"))) {
        date >> day >> delim >> month >> delim >> year;
        type = DDMMYYYY;
    }

    else if (std::regex_match(_data, std::regex("(0[1-9]|1[0-9]|2[0-9]|3[0-1])[-](0[1-9]|1[0-2])[-](194[0-9]|199[0-9]|200[0-9]|202[0-9])\\b"))) {
        date >> day >> delim >> month >> delim >> year;
        type = DD_MM_YYYY;
    }
    else
        throw std::invalid_argument("Bad type");
}

bool Date::isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    return (year % 4 == 0);
}

void Date::add(int _day)
{
    if (_day < 0)
        throw std::invalid_argument("Wrong argument, days must be positive");
    for (int i = 0; i < _day; i++) {
        day++;
        if (day > daysPerMonth[month - 1] || (month == 2 && day == 29 && !isLeapYear(year))) {
            day = 1;
            month++;
            if (month == 13) {
                month = 1;
                year++;
            }
        }
    }
}

void Date::sub(int _day)
{
    if (_day > 0)
        throw std::invalid_argument("Wrong argument, days must be negative");
    for (int i = _day; i < 0; i++) {
        day--;
        if (day == 0) {
            if (month == 2 && isLeapYear(year))
                day = 29;
            else
                day = daysPerMonth[month - 1];
            month--;
            if (month == 0) {
                month = 12;
                year--;
            }
        }
    }
}

int operator-(Date const& _data1, Date const& _data2)
{

    if ((_data1.year < _data2.year) || (_data1.year == _data2.year && _data1.month < _data2.month) || (_data1.year == _data2.year && _data1.month == _data2.month && _data1.day < _data2.day))
        return -1;
    // algoritm from here: https://ru.wikipedia.org/wiki/Юлианская_дата#Вычисление_номера_юлианского_дня_(JDN)_по_дате_григорианского_календаря
    int a1 = (14 - _data1.month) / 12;
    int y1 = _data1.year + 4800 - a1;
    int m1 = _data1.month * 12 * a1 - 3;

    int jdn1 = _data1.day + ((153 * m1 + 2) / 5) + 365 * y1 + (y1 / 4) - (y1 / 100) + (y1 / 400) - 32045;

    int a2 = (14 - _data2.month) / 12;
    int y2 = _data2.year + 4800 - a2;
    int m2 = _data2.month * 12 * a2 - 3;

    int jdn2 = _data2.day + ((153 * m2 + 2) / 5) + 365 * y2 + (y2 / 4) - (y2 / 100) + (y2 / 400) - 32045;

    return (jdn1 - jdn2);
}

std::istream& operator>>(std::istream& is, Date& _data)
{

    std::cout << "Enter day: ";
    is >> _data.day;
    if (_data.day < 1 || _data.day > 31)
        throw std::invalid_argument("Date must be from 1 to 31");
    std::cout << "Enter month: ";
    is >> _data.month;
    if (_data.month < 1 || _data.month > 12)
        throw std::invalid_argument("Month must be from 1 to 12");
    std::cout << "Enter year: ";
    is >> _data.year;
    if (_data.year > 3000)
        throw std::invalid_argument("Year must be no more than 3000");

    _data.type = DDMMYYYY;

    return is;
}

std::ostream& operator<<(std::ostream& os, Date const& _data)
{
    switch (_data.type) {
    case YYYYMMDD:
        os << _data.year << ".";
        os << _data.month << ".";
        os << _data.day;
        break;
    case DDMMYYYY:
        os << _data.day << ".";
        os << _data.month << ".";
        os << _data.year;
        break;
    case DD_MM_YYYY:
        os << _data.day << "-";
        os << _data.month << "-";
        os << _data.year;
        break;
    }

    return os;
}