#include "../interface/Author.h"

Author::Author(std::string name)
{
    this->name = name;
}
void Author::print()
{
    std::cout<< "Author: " << name << std::endl;
}