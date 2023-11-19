#include <iostream>
#include <vector>
#include <string>

// github project blackjack

std::vector<std::string> suitCheck; 
std::vector<std::string> faceCheck;

void exit_func() {
	bool ask;
	std::cout << "Do you wnat to continue? 1/0" << std::endl;
	std::cin >> ask;

	if (ask != 1) {
		exit(0);
	}
}

int hiLowCount(std::string face) {
	int count = 0;

	int val = 0;
	if (face == "Two" || face == "Three" || face == "Four" || face == "Five" || face == "Six") {
		val = 1;
	}
	else if (face == "Seven" || face == "Eight" || face == "Nine") {
		val = 0;
	}
	else {
		val = -1;
	}

	count += val;

	return count;
}

void CheckFunction(std::string suit, std::string face) {

	//std::vector <std::string> suitCheck;
	//std::vector <std::string> faceCheck;

	bool cardIsUnique = true;

	for (int i = 0; i < suitCheck.size(); i++)
	{
		for (int i = 0; i < faceCheck.size(); i++)
		{
			if (suit == suitCheck[i] && face == faceCheck[i]) {
				cardIsUnique = false;
			}

		}
	}

	if (cardIsUnique) { // is true
		suitCheck.push_back(suit);
		faceCheck.push_back(face);
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
	int randomNumberSuit;
	int randomNumberFace;

	

	while (i < CntCard) {

		randomNumberSuit = rand() % suit.size();
		std::cout << "Suit is: " << suit[randomNumberSuit] << std::endl;
		randomNumberFace = rand() % face.size();
		std::cout << "Face is: " << face[randomNumberFace] << std::endl;
		//CntCard++;
		countingValues(face[randomNumberFace], sumPlayer);
		//
		CheckFunction(suit[randomNumberSuit], face[randomNumberFace]);


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
	//if (sumPlayer > 21)
		//std::cout << "Dealers Wins 121212" << std::endl;
	if (sumDealer > sumPlayer && sumDealer < 22) {
		std::cout << "Dealers Wins" << std::endl;
	}
	if (sumDealer == sumPlayer) {
		std::cout << "Tie" << std::endl;
	}
	//return 0;
}

int DealersCardGeneration(std::vector <std::string> suit, std::vector <std::string> face, int &tmpcard) {
	int i = 0;
	int randomNumberFace;
	int randomNumberSuit;
	int sumPlayer = 0;

	randomNumberSuit = rand() % suit.size();
	std::cout << "Suit is: " << suit[randomNumberSuit] << std::endl;
	randomNumberFace = rand() % face.size();
	std::cout << "Face is: " << face[randomNumberFace] << std::endl;
	//
	CheckFunction(suit[randomNumberSuit], face[randomNumberFace]);
	//
	tmpcard = hiLowCount(face[randomNumberFace]);
	//
	countingValues(face[randomNumberFace], sumPlayer);

	return sumPlayer;
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
	//std::vector <std::string> suitCheck;
	//std::vector <std::string> faceCheck;
	int cntCard=0;
	while (true) { // Gaming process

		
		sumDealer = DealersCardGeneration(suit, face, cntCard);
		std::cout << "First dealers card: " << sumDealer << std::endl;

		sumPlayer = cardGeneration(suit, face);
		//checkWin(sumPlayer, sumDealer);
		std::cout << "Sum player is: " << sumPlayer << std::endl;


		// €кщо сума гравц€ б≥льше за 21, то пропускаЇмо другу генерац≥ю карти
		// 
		//dealersCardGeneration

		while (true) {
			if (sumPlayer < 21) {
				int tmp = DealersCardGeneration(suit, face, cntCard);
				sumDealer += tmp;


				std::cout << "Cntcrad: " << cntCard << std::endl;
				std::cout << std::endl;

				std::cout << "Second dealers card: " << sumDealer << std::endl;
				if (sumDealer >= 17) {
					break;
				}
			}
			else
				break;
		}
		
		//sumDealer = cardGeneration(suit, face);
		checkWin(sumPlayer, sumDealer);

		sumDealer = 0;
		sumPlayer = 0;
		exit_func();

		system("cls");
	}


	// розробити перев≥рку на вже застосован≥ карти, щоб в оодномук роз≥граш≥ не було застосовано 2 однаков≥ карти туз черв + туз черв, 
	// €кщо карти зб≥гаютьс€ - згенерувати нову (можна зробити масив з вже згенерованими картами)
}