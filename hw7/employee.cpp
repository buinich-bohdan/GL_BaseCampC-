#include "employee.hpp"

AbstractEmployee::AbstractEmployee()
{
}

AbstractEmployee::AbstractEmployee(const std::string& fn, const std::string& ln, const std::string& j)
    : first_name_(fn)
    , last_name_(ln)
    , job_(j)
{
}

void AbstractEmployee::showAll() const
{
    std::cout << "First name: " << first_name_ << " Second name: " << last_name_ << " Job: " << job_ << std::endl;
}

void AbstractEmployee::setAll()
{
    std::cout << "First name: ";
    std::cin >> first_name_;
    std::cout << "Last name: ";
    std::cin >> last_name_;
    std::cout << "Job: ";
    std::cin >> job_;
}

std::ostream& operator<<(std::ostream& os, const AbstractEmployee& e)
{
    os << "First name: " << e.first_name_ << " Second name: " << e.last_name_;
    return os;
}

AbstractEmployee::~AbstractEmployee()
{
}

Employee::Employee()
    : AbstractEmployee()
{
}
Employee::Employee(const std::string& fn, const std::string& ln, const std::string& j)
    : AbstractEmployee(fn, ln, j)
{
}

void Employee::showAll() const
{
    this->AbstractEmployee::showAll();
}

void Employee::setAll()
{
    this->AbstractEmployee::setAll();
}

Manager::Manager()
    : AbstractEmployee()
    , in_charge_of_(0)
{
}
Manager::Manager(const std::string& fn, const std::string& ln, const std::string& j, int ico)
    : AbstractEmployee(fn, ln, j)
    , in_charge_of_(ico)
{
}

Manager::Manager(const AbstractEmployee& e, int ico)
    : AbstractEmployee(static_cast<const AbstractEmployee&>(e))
    , in_charge_of_(ico)
{
}

Manager::Manager(const Manager& m)
    : AbstractEmployee(static_cast<const AbstractEmployee&>(m))
    , in_charge_of_(m.in_charge_of_)
{
}

void Manager::showAll() const
{
    this->AbstractEmployee::showAll();
    std::cout << "Number of employees manager: " << in_charge_of_ << std::endl; // number of employees manager is in charge of
}

void Manager::setAll()
{
    this->AbstractEmployee::setAll();
    std::cout << "Number of employees: ";
    std::cin >> in_charge_of_;
}

Fink::Fink()
    : AbstractEmployee()
    , reports_to_("none")
{
}

Fink::Fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo)
    : AbstractEmployee(fn, ln, j)
    , reports_to_(rpo)
{
}

Fink::Fink(const AbstractEmployee& e, const std::string& rpo)
    : AbstractEmployee(e)
    , reports_to_(rpo)
{
}

Fink::Fink(const Fink& e)
    : AbstractEmployee(static_cast<const AbstractEmployee&>(e))
    , reports_to_(e.reports_to_)
{
}

void Fink::showAll() const
{
    this->AbstractEmployee::showAll();
    std::cout << "person, who he reports: " << reports_to_ << std::endl; // person, who he reports to
}

void Fink::setAll()
{
    this->AbstractEmployee::setAll();
    std::cout << "Who the fink reports: ";
    std::cin >> reports_to_;
}

HighFink::HighFink()
{
}

HighFink::HighFink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico)
    : AbstractEmployee(fn, ln, j)
{

    Fink::setReportsTo(rpo);
    Manager::setInChargeOf(ico);
}

HighFink::HighFink(const Fink& f, int ico)
    : Fink(f)
{
    setInChargeOf(ico);
}

HighFink::HighFink(const Manager& m, const std::string& rpo)
    : AbstractEmployee(static_cast<const Manager&>(m))
    , Manager(static_cast<const Manager&>(m))
{
    Fink::setReportsTo(rpo);
}

HighFink::HighFink(const HighFink& h) :AbstractEmployee(static_cast<const AbstractEmployee&>(h)) ,Fink(static_cast<const Fink&>(h)), Manager(static_cast<const Manager&>(h))
{
 
}

void HighFink::showAll() const
{
    Fink::showAll();
    std::cout << "in charge of: " << inChargeOf() << std::endl;
}

void HighFink::setAll()
{
    Fink::setAll();
    std::cout << "Number of employees: ";

    int employees;
    std::cin >> employees;
    setInChargeOf(employees);
}