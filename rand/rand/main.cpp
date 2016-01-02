#include <iostream>
#include <time.h>
#include <stdlib.h>

int main(void){
	srand(time(NULL));
	int t = rand() % 10;
	std::cout << t << std::endl;
}