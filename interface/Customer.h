#pragma once
#include <iostream>
#include "Observer.h"

class Customer : public Observer {
 private:
  std::string name;
 public:
  Customer(const std::string& name) : name(name) {}

  void Update(const std::string& availability);
};