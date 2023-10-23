#include <iostream>
#include <vector>
#include <string>

// github project blackjack

void exit_func() {
	bool ask;
	std::cout << "Do you wnat to continue? 1/0" << std::endl;
	std::cin >> ask;

	if (ask != 1) {
		exit(0);
	}
}

int countingValues(std::string Card, int& sum) {
	
	if (Card == "Two") {
		sum += 2;
	}
	if (Card == "Three") {
		sum += 3;
	}
	if (Card == "Four") {
		sum += 4;
	}
	if (Card == "Five") {
		sum += 5;
	}
	if (Card == "Six") {
		sum += 6;
	}
	if (Card == "Seven") {
		sum += 7;
	}
	if (Card == "Eight") {
		sum += 8;
	}
	if (Card == "Nine") {
		sum += 9;
	}
	if (Card == "King" || Card == "Queen" || Card == "Jock" || Card == "Ten") {
		sum += 10;
	}
	if (Card == "Ace" && sum + 11 <= 21) {
		sum += 11;
	}
	else if (Card == "Ace" && sum + 11 > 21){
		sum +=1;
	}
	return sum;
}


int cardGeneration(std::vector <std::string> suit, std::vector <std::string> face) {
	
	int i = 0;
	int CntCard = 2;
	int sumPlayer = 0;
	int randomNumber;
	

	while (i < CntCard) {

		randomNumber = rand() % suit.size();
		std::cout << "Suit is: " << suit[randomNumber] << std::endl;
		randomNumber = rand() % face.size();
		std::cout << "Face is: " << face[randomNumber] << std::endl;
		//CntCard++;
		countingValues(face[randomNumber], sumPlayer);

		if (sumPlayer > 21) {
			std::cout << "Dealer Wins" << std::endl;
			return sumPlayer;
		}

		i++;
		if (i == CntCard) {

			bool ask;
			std::cout << "Dou you want more ? " << std::endl;
			std::cin >> ask;

			if (ask == 1) {
				CntCard++;
			}
		}
	}

	return sumPlayer;
}

void checkWin(int sumPlayer, int sumDealer) {

	if (sumPlayer == 21 && sumDealer != 21)
		std::cout << "Player Wins" << std::endl;
	if (sumPlayer > sumDealer && sumPlayer < 22) // duplicate with dealer
		std::cout << "Player Wins" << std::endl;
	if (sumDealer > 21)
		std::cout << "Player Wins" << std::endl;
	if (sumPlayer > 21)
		std::cout << "Dealers Wins" << std::endl;
	if (sumDealer > sumPlayer && sumDealer < 22) {
		std::cout << "Dealers Wins" << std::endl;
	}
	if (sumDealer == sumPlayer) {
		std::cout << "Tie" << std::endl;
	}
	//return 0;
}

int main() {

	//srand(time(0));

	std::vector <std::string> suit = { "Clubs", "Hearts", "Diamodns", "Spades" };
	std::vector <std::string> face = { "Ace","King","Queen", "Jock", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two" };

	/*for (int i = 0; i < suit.size(); i++) {
		std::cout << "T is: " << suit[i] << std::endl;
	}*/

	int sumPlayer;
	int sumDealer = 0;
	int dealer = 0;
	int randomNumber = 0;
	//std::cout << "Rand num: " << randomNumber << std::endl;

	//bool isGame;
	while (true) {

		sumPlayer = cardGeneration(suit, face);
		//checkWin(sumPlayer, sumDealer);
		std::cout << "Sum is: " << sumPlayer << std::endl;
		sumDealer = cardGeneration(suit, face);
		checkWin(sumPlayer, sumDealer);
		exit_func();

		system("cls");
	}
	// розробити процесс гри таким чином, спочатку показуЇтьс€ 1 карта дилера, пот≥м 2 карти гравц€, пот≥м 2-га карта дилера, ≥ €кщо потр≥бна 3-т€...
	// написати простий алгоритм прийн€тт€ р≥шень дилером - €кщо к≥льк≥сть очок дилера 17 або б≥льше, то в≥н не бере б≥льше карти
	// в ≥ншому випадку бере до тих п≥р поки сума не буде б≥льше дор≥внювати 17
	// розробити перев≥рку на вже застосован≥ карти, щоб в оодномук роз≥граш≥ не було застосовано 2 однаков≥ карти туз черв + туз черв, 
	// €кщо карти зб≥гаютьс€ - згенерувати нову (можна зробити масив з вже згенерованими картами)
}