#include <Individual.h>
#include <Standard.h>
#include <Strategy.h>

#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

Standard::~Standard() {
  for (auto i : lists) {
    delete i;
  }

  for (auto i : extraDel) {
    delete i;
  }
}

void Standard::newList(Library *library) {
  Composition *newList = new Composition();

  std::string name;
  std::string ws;
  std::cout << "List name: ";
  std::cin.ignore();
  std::getline(std::cin, name);
  newList->SetName(name);

  int IDnum;
  int input = 1;
  while (input != 0) {
    std::cout << "1. Add book with ID" << std::endl;
    std::cout << "2. Add a List" << std::endl;
    std::cout << "0. Stop" << std::endl;

    std::cin >> input;
    if (input == 1) {
      std::cout << "Enter the ID of the book: ";
      std::cin >> IDnum;

      Book *b = library->FindBook(IDnum);
      if (b == nullptr) {
        std::cout << "Book does not exist" << std::endl;
        continue;
      }
      Individual *entry = new Individual();
      entry->SetBook(b);
      newList->Add(entry);
      std::cout << entry->GetBook()->GetTitle() << " was added to your list"
                << std::endl
                << std::endl;

      extraDel.push_back(entry);
    } else if (input == 2) {
      if (lists.size() != 0) {
        std::cout << "Enter name of list you would like to add: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        for (auto i : lists) {
          if (name == i->GetName()) {
            newList->Add(i);
            std::cout << name << " was added to your list" << std::endl
                      << std::endl;
          }
        }
      } else {
        std::cout << "Error: No Lists available" << std::endl;
      }
    } else {
      if (input != 0) {
        std::cout << "Invalid Input" << std::endl;
      }
    }
  }
  lists.push_back(newList);
}

void Standard::viewLists() {
  int index = 1;
  for (auto i : lists) {
    if (index == lists.size()) {
      i->print(0, 1);
    } else {
      i->print(0, 0);
    }
    ++index;
  }
}

void Standard::recommend(Library *lib) {
  std::cout << std::setw(25) << "Genre" << std::setw(55) << "Title"
            << std::setw(35) << "Author" << std::setw(7) << "ID" << std::endl;
  std::cout << "---------------------------------------------------------------"
               "-----------------------------------------------------------"
            << std::endl;

  // TODO: Both algorithms work independently meaning repeat entires may be
  // outputted
  Favorites *alg1 = new Favorites();
  alg1->recommendation_algorithm(history, lib, 0);
  Popular *alg2 = new Popular();
  alg2->recommendation_algorithm(history, lib, 0);

  delete alg1;
  delete alg2;
}

void Standard::AddCheckedOut(Book *book) {
  if (book != nullptr) {
    checkedOut.push_back(book);
  }
}

void Standard::AddHistory(std::pair<Book *, double> data) {
  history.insert(data);
}

void Standard::AddLists(Composition *list) { lists.push_back(list); }

void Standard::AddExtraDel(Lists *lst) { extraDel.push_back(lst); }

void Standard::checkoutBook(Book *b) {
  for (auto i : checkedOut) {
    if (i->GetID() == b->GetID()) {
      std::cout << "You already have this book checked out." << std::endl;
      return;
    }
  }
  checkedOut.push_back(b);
  std::cout << "Book with ID: " << b->GetID()
            << " has been successfully checked out to User." << std::endl;
}

void Standard::returnBook(Book *b, int index) {
  double rating = -1.0;
  checkedOut.erase(checkedOut.begin() + index);
  std::cout << "Book with ID: " << b->GetID()
            << " has been successfully returned to the Library." << std::endl;
  while (rating < 1.0 || rating > 5.0) {
    std::cout << "From 1 to 5 (1 being the worst, 5 being the best), please "
                 "input your rating of this book: ";
    std::cin >> rating;
    std::cout << std::endl;
  }
  this->history.insert(std::pair<Book *, double>(b, rating));
  std::cout << "You have given the book with ID: " << b->GetID()
            << " a rating of " << rating << "." << std::endl;

  // TODO: Update this in database since we are no longer storing back into file
  b->SetRating(((b->GetRating() * b->GetNumReviews()) + rating) /
               (b->GetNumReviews() + 1));
  b->SetNumReviews(b->GetNumReviews() + 1);
}

void Standard::displayBooks() {
  for (unsigned i = 0; i < checkedOut.size(); i++) {
    std::cout << checkedOut.at(i)->GetTitle() << std::endl;
  }
}
