#pragma once

#include <iostream>
#include <cstring>

class Port {
protected:
    char* brand;
    char style[20]; // e.g. tawny, ruby, vintage
    int bottles;

public:
    Port(const char* br = "none", const char* st = "none", int b = 0);
    Port(const Port&);
    virtual ~Port();

    Port& operator=(const Port&);
    Port& operator+=(int); // adds b to bottles
    Port& operator-=(int); // subtracts b from bottles, if possible

    int BottleCount() const;
    virtual void Show() const;
    friend std::ostream& operator<<(std::ostream&, const Port&);
};

std::ostream& operator<<(std::ostream&, const Port&);