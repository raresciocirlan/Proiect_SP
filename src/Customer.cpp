#include "../interface/Customer.h"

void Customer::Update(const std::string& availability)
{
    std::cout << name << ": The availability of books is now " << availability << std::endl;
}