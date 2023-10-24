#pragma once

#include "Lists.h"

#include <fstream>
#include <string>
#include <vector>

class Composition : public Lists {
private:
  std::string list_name;
  std::vector<Lists *> list;

public:
  virtual std::string print(int space, int key);
  virtual void file(std::ofstream &fout);
  virtual void find_rating();
  virtual std::string return_type();
  void Add(Lists *obj);
  std::vector<Lists *> GetList();
  std::string GetName();
  void SetName(std::string name);
};