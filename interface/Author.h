#pragma once
#include <string.h>
#include <iostream>

class Author
{
private:
    std::string name;
    std::string surName;
public:
    Author(std::string name);
    void print();
};