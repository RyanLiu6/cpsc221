#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int crown, guess;
	bool yah = false;

	// intialize random seed
	srand(time(NULL));
	//crown = rand() % 100 + 1;
	crown = 44;

	// Using Standard Library
	/*
	do {
		if (yah) {
			printf("Enter 0 if you wish to quit.\n");
		}

		printf("Enter your guess: \n");
		scanf("%d", &guess);

		if (guess == 0) {
			break;
		}

		if (guess != crown){
			printf("Incorrect - Please try again.\n");
		}
		yah = true;
	} while (guess != crown);

	if (guess == crown) printf("Correct!\n");
	printf("Thank you and have a great day\n");
	*/

	// Using iostream
		do {
		if (yah) {
			std::cout << "Enter 0 if you wish to quit." << std::endl;
		}

		std::cout << "Enter your guess: " << std::endl;
		std::cin >> guess;

		if (guess == 0) {
			break;
		}

		if (guess != crown){
			std::cout << "Incorrect - Please try again." << std::endl;
		}

		yah = true;

	} while (guess != crown);

	if (guess == crown) {
		std::cout << "Correct!!" << std::endl;
	}
	std::cout << "Thank you and have a great day!" << std::endl;
}