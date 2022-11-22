#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* k;
	const Animal* j = new Dog;
	const Animal* i = new Cat;
	//k = new Dog;
	delete j;//should not create a leak
	delete i;
	system("leaks Abstract");
}