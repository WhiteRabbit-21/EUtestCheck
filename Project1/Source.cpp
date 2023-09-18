#include <iostream>
#include <vector>
#include <string>

// github project blackjack

int main() {

	std::vector <std::string> T = {"Clubs", "Hearts", "Diamodns", "Spades"};

	for (int i = 0; i < T.size(); i++) {
		std::cout << "T is: " << T[i] << std::endl;
	}
}