#include <iostream>
#include "User.h"

int main() {
	Database TestBase;

	TestBase.addUser(User("Gandon", 0));
	TestBase.addUser(User("Pizda", 1));
	TestBase.addUser(User("Eblan", 2));
	TestBase.addUser(User("Stupid", 7));
	TestBase.addUser(User("Wtf", 3));

	User* user = TestBase.findUserByName("Stupid");
	TestBase.optimizeUserList();
	TestBase.modifyUser(3, "Idiot");
	if (user) {
		std::cout << "Found User: " << user->getName() << ", Id: " << user->getId() << std::endl;
	}
	else {
		std::cout << "User not found" << std::endl;
	}

	return 0;

	// int sus = 5;
	// std::cout << sus;
}
