#include <string>
#include "Book.hpp"

Book::Book(std::string title, std::string author, std::string genre, int ID, double rating, int numReviews) {
	this->title = title;
	this->author = author;
	this->genre = genre;
	this->ID = ID;
	this->rating = rating;
	this->numReviews = numReviews;
}

Book::Book(const Book& b) {
        title = b.GetTitle();
        author = b.GetAuthor();
        genre = b.GetGenre();
        ID = b.GetID();
        rating = b.GetRating();
	numReviews = b.GetNumReviews();
} 

std::string Book::GetTitle() const {return title;}
std::string Book::GetAuthor() const {return author;}
std::string Book::GetGenre() const {return genre;}
int Book::GetID() const {return ID;}
double Book::GetRating() const {return rating;}
int Book::GetNumReviews() const {return numReviews;}

void Book::SetTitle(std::string title) {this->title = title;}
void Book::SetAuthor(std::string author) {this->author = author;}
void Book::SetGenre(std::string genre) {this->genre = genre;}
void Book::SetID(int ID) {this->ID = ID;}
void Book::SetRating(double rating) {this->rating = rating;}
void Book::SetNumReviews(int numReviews) {this->numReviews = numReviews;}

