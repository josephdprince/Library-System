#include <Strategy.h>

#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

std::string Favorites::recommendation_algorithm(std::map<Book *, double> list,
                                                Library *lib, bool key) {
  std::vector<Book *> likedBooks;
  for (auto i : list) {
    if (i.second >= 4.0) {
      likedBooks.push_back(i.first);
    }
  }
  // We now have a vector of books that the user likes
  int index = 0;
  std::set<std::string> likedGenres;
  for (auto i : likedBooks) {
    // MongoDB gives me the value in quotes. substr removes them
    likedGenres.insert(i->GetGenre().substr(1, i->GetGenre().size() - 2));
  }
  for (auto i : likedGenres) {
    lib->DisplayGenre(i);
  }

  // TODO: This string is used for gtests and was removed with the mongoDB
  // implmentation. In the future, add logic to allow gtests to work using this
  // string
  return "";
}

std::string Popular::recommendation_algorithm(std::map<Book *, double> list,
                                              Library *lib, bool key) {

  lib->DisplayPopular();

  // TODO: This string is used for gtests and was removed with the mongoDB
  // implmentation. In the future, add logic to allow gtests to work using this
  // string
  return "";
}
