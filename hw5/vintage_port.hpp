#pragma once
#include "port.hpp"

class VintagePort : public Port { // style always == "vintage"
private:
    char* nickname; // like "The Noble", "Old Velvet", etc.
    int year; // year of bottling
public:
    VintagePort();
    VintagePort(const char*, int, const char*, int);
    VintagePort(const VintagePort&);
    ~VintagePort();

    VintagePort& operator=(const VintagePort&);
    void Show() const;
    friend std::ostream& operator<<(std::ostream&, const VintagePort&);
};

std::ostream& operator<<(std::ostream&, const VintagePort&);