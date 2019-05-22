#include <cstdlib> // for atoi
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

// prototype 
void moveDisks(int n, const char* FROM, const char* VIA, const char* TO);
void move(const char* FROM, const char* TO);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " number_of_disks" << std::endl;
    return -1;
  }
  int n = atoi(argv[1]);
  moveDisks(n, "peg A", "peg B", "peg C");
  return 0;
}

// put your moveDisks() function here 
void moveDisks(int n, const char* FROM, const char* VIA, const char* TO) {
	if (n >= 1) {
		moveDisks((n-1), FROM, TO, VIA);
		move(FROM, TO);
		moveDisks((n-1), VIA, FROM, TO);
	}
}

void move(const char* FROM, const char* TO) {
	/* Using Standard Library
	   printf("Moving Disk from %s ", &*FROM);
	   printf("to %s\n", &*TO);
	*/

	// Using iostream
	std::cout << "Moving Disk from " << &*FROM << " to " << &*TO << std::endl;
}
