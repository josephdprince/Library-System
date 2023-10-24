#include "../include/Individual.h"

#include <iostream>

std::string Individual::print(int space, int key) {
  std::string str = "";
  for (int i = 0; i < space; ++i) {
    std::cout << "    ";
    str += "    ";
  }
  std::cout << "- " << book->GetTitle() << " by " << book->GetAuthor()
            << std::endl;
  str += "- " + book->GetTitle() + "\n";
  return str;
}

void Individual::file(std::ofstream &fout) {
  fout << book->GetID() << std::endl;
}

void Individual::find_rating() {
  std::cout << book->GetTitle() << " is rated " << book->GetRating() << "/5.0"
            << std::endl;
}

std::string Individual::return_type() { return "Individual"; }

Book *Individual::GetBook() { return book; }

void Individual::SetBook(Book *book) { this->book = book; }