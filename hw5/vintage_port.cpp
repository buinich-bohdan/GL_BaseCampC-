#include "vintage_port.hpp"

VintagePort::VintagePort()
    : Port("none", "vintage", 0)
    , nickname(strcpy(new char[strlen("none")], "none"))
    , year(0)
{
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
    : Port(br, "vintage", b)
    , year(y)
{
    if (nn) {
        nickname = new char[strlen(nn)];
        strcpy(nickname, nn);
    }
    else
        strcpy(nickname, "none");
}

VintagePort::VintagePort(const VintagePort& vp)
    : Port(static_cast<const Port&>(vp))
    , nickname(strcpy(new char[strlen(vp.nickname)], vp.nickname))
    , year(vp.year)
{
}

VintagePort::~VintagePort()
{
    delete[] nickname;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
    if (this != &vp) {
        delete[] brand;
        delete[] nickname;

        brand = strcpy(new char[strlen(vp.brand)], vp.brand);
        strcpy(style, vp.style);
        bottles = vp.bottles;
        nickname = strcpy(new char[strlen(vp.nickname)], vp.nickname);
        year = vp.year;
    }
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Year: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
    os << vp.brand << ", " << vp.style << ", " << vp.bottles << ", " << vp.nickname << ", " << vp.year;
    return os;
}