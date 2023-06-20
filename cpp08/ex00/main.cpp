#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <random>

#define ARRNUM 40
int main() {

	int x;
	x = ARRNUM;

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 100);

	std::vector<int> vec;
	for (int i = 0; i < x; i++) 
		vec.push_back(dist(mt));

	std::vector<int>::iterator num = vec.begin();
	std::cout << "Números aleatorios generados:" << std::endl;
	for (unsigned long i=0; i < vec.size(); i++) {
		std::cout << *num++ << " ";
	}
	std::cout << std::endl << std::endl << std::endl;

	try{
		int value = dist(mt);
		std::cout << "Find this number: (" << value << ")" << std::endl;
		std::vector<int>::iterator iter = easyfind(vec, value);
		std::cout << "Found number: (" << *iter << ")" << std::endl;
		
		std::cout << "Element " << *iter << " found at index: " << std::distance(vec.begin(), iter) << std::endl;
		
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}
