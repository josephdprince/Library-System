#include "Book.h"
#include <string>

Book::Book(std::string title, std::string author, std::string genre, int ID) {
	this->title = title;
	this->author = author;
	this->genre = genre;
	this->ID = ID;
	
	rating = 0;
	numReviews = 0;
} 

std::string Book::GetTitle() {return title;}
std::string Book::GetAuthor() {return author;}
std::string Book::GetGenre() {return genre;}
int Book::GetID() {return ID;}
double Book::GetRating() {return rating;}
int Book::GetNumReviews() {return numReviews;}

void Book::SetTitle(std::string title) {this->title = title;}
void Book::SetAuthor(std::string author) {this->author = author;}
void Book::SetGenre(std::string genre) {this->genre = genre;}
void Book::SetID(int ID) {this->ID = ID;}
void Book::SetRating(double rating) {this->rating = rating;}
void Book::SetNumReviews(int numReviews) {this->numReviews = numReviews;}

