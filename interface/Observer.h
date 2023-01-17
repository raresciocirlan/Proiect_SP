#pragma once
#include <iostream>

class Observer {
 public:
  virtual void Update(const std::string& availability) = 0;
};