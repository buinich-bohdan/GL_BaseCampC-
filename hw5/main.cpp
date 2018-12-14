#include "vintage_port.hpp"

int main(int argc, char const* argv[])
{
    Port* a = new VintagePort();
    a->Show();
    std::cout << "______________________" << std::endl;
    VintagePort* b = new VintagePort("Gallo", 20, "The Noble", 1995);
    b->Show();
    std::cout << "______________________" << std::endl;
    a = b;
    a->Show();

    std::cout << "without static_cast---> " << *a << std::endl;
    std::cout << "with static_cast---> 	" << static_cast<VintagePort&>(*a) << std::endl;

    *a -= 5;
    std::cout << "sub 5 bottles " << *a << std::endl;

    *a += 10;
    std::cout << "add 10 bottles " << *a << std::endl;

    return 0;
}