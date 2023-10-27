#pragma once

#include <fstream>
#include <string>

class Lists {
public:
  virtual ~Lists(){};
  virtual std::string print(int, int) = 0;
  virtual void file(std::ofstream &) = 0;
  virtual void find_rating() = 0;
  virtual std::string return_type() = 0;
};
