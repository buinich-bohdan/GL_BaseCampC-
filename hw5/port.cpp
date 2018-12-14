#include "port.hpp"

Port::Port(const char* br, const char* st, int b)
    : bottles(b)
{
    if (br) {
        brand = new char[strlen(br)];
        strcpy(brand, br);
    }
    else
        strcpy(brand, "none");

    if (st)
        strncpy(style, st, 20);
    else
        strcpy(style, "none");
}

Port::Port(const Port& p)
    : bottles(p.bottles)
{
    brand = new char[strlen(p.brand)];
    strcpy(brand, p.brand);
    strncpy(style, p.style, 20);
}

Port::~Port()
{
    delete[] brand;
}

Port& Port::operator=(const Port& p)
{
    if (this != &p)
        if (brand)
            delete[] brand;
    brand = new char[strlen(p.brand)];
    strcpy(brand, p.brand);
    strncpy(style, p.style, 20);
    bottles = p.bottles;
    return *this;
}

Port& Port::operator+=(int b)
{
    this->bottles += b;
    return *this;
} // adds b to bottles

Port& Port::operator-=(int b)
{
    if (this->bottles >= b)
        this->bottles -= b;
    else
        bottles = 0;
    return *this;
} // subtracts b from bottles, if possible

int Port::BottleCount() const
{
    return bottles;
}

void Port::Show() const
{
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Kind: " << style << std::endl;
    std::cout << "Bottles: " << bottles << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Port& p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}
