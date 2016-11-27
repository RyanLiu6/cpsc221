#include <omp.h>
#include <iostream>

int main( int argc, char *argv[] ) {
	int nProc = omp_get_max_threads();

	omp_set_num_threads(nProc);
	std::cout << omp_get_num_threads() << std::endl;
	int count = 0;

	#pragma omp parallel
  	{
		count++;
		// Code inside this region runs in parallel.
    	printf("Hello!\n");
	}
	std::cout << count << std::endl;
}