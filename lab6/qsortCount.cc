#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;
int comps;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		comps++;
		if (x[i] < x[a])
			swap(x[++m], x[i]);
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

int qc(int n) {
	if (n <= 1)
		return 0;
	// Picking a random pivot between 0 and n-1
	int pivot = randint(0, n-1);
	// For each pivot, there are n-1 comparisons
	int count = n - 1;
	// Recurrence relationship of quicksort from above
	// Do the left side of pivot then do the right side of pivot
	return count + qc(pivot) + qc(n - pivot - 1);
}

/* Given c(n), find recurrence relation
 * C(n): If n = 0 or 1, C(n) = 0, else
 * C(n) = sum from i = 1 to n of
 * [(n-1) + C(i - 1) + C(n - i)] / n
 */
float c(int n) {
	if (n <= 1) return 0;
	float sum = 0.0;
	for (int m=1; m <= n; m++)
		sum += n-1 + c(m-1) + c(n-m);
	return sum / n;
}

#define NN 1000

int main(int argc, char *argv[]) {
	srand(time(0));

	// change the following code
	x = new int[NN];
	for (int i=0; i<NN; ++i) {
		x[i] = rand() % NN;
	}
	
	quicksort(0, NN-1);
	for (int i=0; i<NN; ++i) {
		std::cout << x[i] << " ";
	}
	std::cout << std::endl;

	int count_2 = qc(NN);

	std::cout << "Num Comparisons = " << comps << std::endl;
	std::cout << "Num Comparisons = " << count_2 << std::endl;
	delete[] x;
	return 0;
}