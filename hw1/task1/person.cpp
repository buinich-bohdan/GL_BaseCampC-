#include "person.hpp"
#include "utility"
#include <string.h>
#include <iostream>

Person::Person()
    : mLastName("")
    , mFirstName{ '\0' }
{
}

Person::Person(const std::string ln, const char* fn)
    : mLastName(std::move(ln))
{
    strncpy(mFirstName, fn, LIMIT - 2);
}

void Person::Show() const
{
    std::cout << mFirstName << " " << mLastName << std::endl;
}

void Person::FormalShow() const
{
    std::cout << mLastName << " " << mFirstName << std::endl;
}