#include "../include/Composition.h"
#include "../include/Book.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string Composition::print(int space, int key) {
  std::string str = "";
  for (int i = 0; i < space; ++i) {
    std::cout << "    ";
    str += "    ";
  }
  std::cout << list_name << ":" << std::endl;
  str += list_name + ":\n";
  for (auto i : list) {
    str += i->print(space + 1, key);
  }
  if (space == 0 && key != 1) {
    std::cout << std::endl;
    str += "\n";
  }
  return str;
}

void Composition::file(std::ofstream &fout) {
  fout << "/" << std::endl;
  fout << list_name << std::endl;
  for (auto i : list) {
    i->file(fout);
  }
  fout << "}" << std::endl;
}

void Composition::find_rating() {
  for (auto i : list) {
    i->find_rating();
  }
}

std::string Composition::return_type() { return "Composition"; }

void Composition::Add(Lists *obj) { list.push_back(obj); }

std::vector<Lists *> Composition::GetList() { return list; }

void Composition::SetName(std::string name) { list_name = name; }

std::string Composition::GetName() { return list_name; }
