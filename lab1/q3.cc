#include <iostream>

void fill_array(int a, int b);
int arr[10];

int main(void) {
	int n = 10;
	int a, b;

	std::cout << "Enter starting number:" << std::endl;
	std::cin >> a;
	std::cout << "Enter increment amount:" << std::endl;
	std::cin >> b;

	fill_array(a, b);
	for (int i = 0; i < (n-1); i++) {
		std::cout << arr[i] << std::endl;
	}
	return 0;
}

void fill_array(int a, int b) {
	int i = 0;
	arr[i] = a;

	for (i = 1; i < 9; i++) {
		arr[i] = arr[i-1] + b;
	}
}