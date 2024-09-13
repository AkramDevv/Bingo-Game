#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

const int MAX = 50;

void fill_card_random(int arr[], int size) {
	for (int i = 0;i < size;i++) {
		arr[i] = rand() % 89 + 1;
	}
}

void print_card(int arr[], int size) {
	for (int i = 0;i < size;i++) {
		std::cout << arr[i] << " ";
	}
}

bool check_number(int arr[], int size, int pocket_number) {
	bool find = false;
	for (int i = 0;i < size;i++) {
		if (arr[i] == pocket_number && arr[i] != 0) {
			arr[i] = 0;
			find = true;
		}
	}
	return find;
}

bool check_winner(int arr[], int size) {
	bool findZero = true;
	for (int i = 0;i < size;i++) {
		if (arr[i] != 0) {
			findZero = false;
		}
	}
	return findZero;
}

int main() {

	srand(time(NULL));

	int cardSize = 5;
	int card1[MAX], card2[MAX], card3[MAX];

	fill_card_random(card1, cardSize);
	fill_card_random(card2, cardSize);
	fill_card_random(card3, cardSize);

	std::cout << "\nFirst card's numbers: \n";
	print_card(card1, cardSize);
	std::cout << "\n\nSecond card's numbers: \n";
	print_card(card2, cardSize);
	std::cout << "\n\nThird card's numbers: \n";
	print_card(card3, cardSize);

	int chanceCount;
	std::cout << "\nEnter chance count: ";
	std::cin >> chanceCount;

	int card1_chance = chanceCount;
	int card2_chance = chanceCount;
	int card3_chance = chanceCount;

	int choice;
	std::cout << "\nWhich you want? - Enter numbers from pocket 1.Manual || 2.Random: ";
	std::cin >> choice;

	std::chrono::seconds twoSec = std::chrono::seconds(2);
	if (choice == 1) {
		bool winner = true;
		while (winner) {

			int pockNum;

			if (card1_chance > 0) {
				std::cout << "\nFirst card - Enter number from pocket: ";
				std::cin >> pockNum;
				if (!(check_number(card1, cardSize, pockNum))) {
					card1_chance--;
				}
				std::cout << "\n\nFirst card's numbers: \n";
				print_card(card1, cardSize);
				std::cout << std::endl << "Card 1 have " << card1_chance << " chances.\n";
			}

			if (card2_chance > 0) {
				std::cout << "\n\nSecond card - Enter number from pocket: ";
				std::cin >> pockNum;
				if (!(check_number(card2, cardSize, pockNum))) {
					card2_chance--;
				}
				std::cout << "\n\nSecond card's numbers: \n";
				print_card(card2, cardSize);
				std::cout << std::endl << "Card 2 have " << card2_chance << " chances.\n";
			}

			if (card3_chance > 0) {
				std::cout << "\n\nThird card - Enter number from pocket: ";
				std::cin >> pockNum;
				if (!(check_number(card3, cardSize, pockNum))) {
					card3_chance--;
				}
				std::cout << "\n\nThird card's numbers: \n";
				print_card(card3, cardSize);
				std::cout << std::endl << "Card 3 have " << card3_chance << " chances.\n";
			}

			if (check_winner(card1, cardSize) || (card1_chance != 0 && card2_chance == 0 && card3_chance == 0)) {
				std::cout << "\n----------------------------------\n";
				std::cout << "The winner is Card 1 Player!!!";
				std::cout << "\n----------------------------------\n";
				winner = false;
			}
			else if (check_winner(card2, cardSize) || (card2_chance != 0 && card1_chance == 0 && card3_chance == 0)) {
				std::cout << "\n----------------------------------\n";
				std::cout << "The winner is Card 2 Player!!!";
				std::cout << "\n----------------------------------\n";
				winner = false;
			}
			else if (check_winner(card3, cardSize) || (card3_chance != 0 && card1_chance == 0 && card2_chance == 0)) {
				std::cout << "\n----------------------------------\n";
				std::cout << "The winner is Card 3 Player!!!";
				std::cout << "\n----------------------------------\n";
				winner = false;
			}
			else if (card1_chance == 0 && card2_chance == 0 && card3_chance == 0) {

				std::cout << "\n----------------------------------\n";
				std::cout << "Draw!!!";
				std::cout << "\n----------------------------------\n";
				winner = false;
			}
		}
	}

	else if (choice == 2) {

		bool winner = true;
		while (winner) {
			int pockNum;

			if (card1_chance > 0) {
				pockNum = rand() % 89 + 1;
				std::cout << "\nFirst card - Entered random number from pocket: " << pockNum;
				if (!(check_number(card1, cardSize, pockNum))) {
					card1_chance--;
				}
				std::cout << "\n\nFirst card's numbers: \n";
				print_card(card1, cardSize);
				std::cout << std::endl << "Card 1 have " << card1_chance << " chances.\n";
				std::this_thread::sleep_for(twoSec);
			}

			if (card2_chance > 0) {
				pockNum = rand() % 89 + 1;
				std::cout << "\nSecond card - Entered random number from pocket: " << pockNum;
				if (!(check_number(card2, cardSize, pockNum))) {
					card2_chance--;
				}
				std::cout << "\n\nSecond card's numbers: \n";
				print_card(card2, cardSize);
				std::cout << std::endl << "Card 2 have " << card2_chance << " chances.\n";
				std::this_thread::sleep_for(twoSec);
			}

			if (card3_chance > 0) {
				pockNum = rand() % 89 + 1;
				std::cout << "\nThird card - Entered random number from pocket: " << pockNum;
				if (!(check_number(card3, cardSize, pockNum))) {
					card3_chance--;
				}
				std::cout << "\n\nThird card's numbers: \n";
				print_card(card3, cardSize);
				std::cout << std::endl << "Card 3 have " << card3_chance << " chances.\n";
				std::this_thread::sleep_for(twoSec);
			}

			if (check_winner(card1, cardSize) || (card1_chance != 0 && card2_chance == 0 && card3_chance == 0)) {
				std::cout << "\n----------------------------------\n";
				std::cout << "The winner is Card 1 Player!!!";
				std::cout << "\n----------------------------------\n";
				winner = false;
			}
			else if (check_winner(card2, cardSize) || (card2_chance != 0 && card1_chance == 0 && card3_chance == 0)) {
				std::cout << "\n----------------------------------\n";
				std::cout << "The winner is Card 2 Player!!!";
				std::cout << "\n----------------------------------\n";
				winner = false;
			}
			else if (check_winner(card3, cardSize) || (card3_chance != 0 && card1_chance == 0 && card2_chance == 0)) {
				std::cout << "\n----------------------------------\n";
				std::cout << "The winner is Card 3 Player!!!";
				std::cout << "\n----------------------------------\n";
				winner = false;
			}
			else if (card1_chance == 0 && card2_chance == 0 && card3_chance == 0) {

				std::cout << "\n----------------------------------\n";
				std::cout << "Draw!!!";
				std::cout << "\n----------------------------------\n";
				winner = false;
			}
		}
	}


	return 0;
}