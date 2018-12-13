#pragma once
#include <string>

class Person {
private:
    constexpr static int LIMIT = 25;
    std::string mLastName; // Person's last name
    char mFirstName[LIMIT]; // Person's first name
public:
    Person();
    Person(const std::string, const char* fn = "Heyyou"); // #2
    // the following methods display mLastName and mFirstName
    void Show() const; // firstname lastname format
 	void FormalShow() const; // lastname, firstname format
};