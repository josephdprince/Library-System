#include <iostream>
#include "Library.h"

int main() {
	Library lib;
	if(!lib.loadUsers()) {
		std::cerr << "ERROR: Cannot load users from login.csv" << std::endl;
		exit(1);
	}
	
	lib.login();

	return 0;
}
