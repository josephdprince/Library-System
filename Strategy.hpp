#ifndef __STRATEGY_HPP__
#define __STRATEGY_HPP__
#include <iostream>
#include <map>
#include <vector>

#include "Book.hpp"

class Strategy {
    public:
        virtual void recommendation_algorithm(std::map<Book*, double>, std::vector<Book*>) = 0;
};
//This will go off of books user already likes
class Algorithm_1 : public Strategy {
    public:
        virtual void recommendation_algorithm(std::map<Book*, double> list, std::vector<Book*> library) {
            std::vector<Book*> likedBooks;
            for (auto i : list) {
                if (i.second >= 4.0) {
                    likedBooks.push_back(i.first);
                }
            }
	    //We now have a vector of books that the user likes.
	    for (auto i : library) {
                for (auto j : likedBooks) {
                    if (i->GetGenre() == j->GetGenre() && i->GetTitle() != j->GetTitle()) {
                        std::cout << i->GetTitle() << " by " << i->GetAuthor() << std::endl;
                    }
                }
            }
        }
};

//this will go off of popular books in the library
class Algorithm_2 : public Strategy {
    public:
        virtual void recommendation_algorithm(std::map<Book*, double> list, std::vector<Book*> library) {
            for (auto i : library) {
                if (i->GetRating() > 3.5) {
                    std::cout << i->GetTitle() << " by " << i->GetAuthor() << std::endl;
                }
            }
        }
};

#endif
