#include "golf.hpp"
#include <cstring>
#include <iostream>

void setGolf(golf& g, const char* name, int hc)
{
    strncpy(g.fullname, name, Len - 1);
    g.handicap = hc;
}

int setGolf(golf& g)
{
	std::string name;

	std::cout << "Enter name: ";
	std::getline(std::cin, name);
	strncpy(g.fullname, name.c_str(), Len - 1);

	std::cout << "Enter handicap: ";
	std::cin >> g.handicap;
	
    return (strlen(g.fullname) == 0) ? 0 : 1;
}

void handicap(golf& g, int hc)
{
    setGolf(g, g.fullname, hc);
}

void showGolf(const golf& g)
{
    std::cout << "Name: " << g.fullname << " Handicap: " << g.handicap << std::endl;
}