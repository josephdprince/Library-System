#include <iomanip>
#include "Library.h"
using namespace std;

void Library::DisplayGenre(string genre) {
	for (int i = 0; i < library.size(); i++) {
		if (library.at(i)->GetGenre() == genre) {
			cout << library.at(i)->GetTitle() << " by " << library.at(i)->GetAuthor();
	}
}

void Library::DisplayAll() {
	cout << setw(20) << "Genre" << setw(50) << "Title" << setw(35) << "Author" << setw(7) << "ID" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < library.size(); i++) {
		cout << setw(20) << library.at(i)->GetGenre() <<  setw(50) << library.at(i)->GetTitle()
		     << setw(35) << library.at(i)->GetAuthor() << setw(7) << library.at(i)->GetID() << endl;
	}
}
