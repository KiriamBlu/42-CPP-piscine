#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	const WrongAnimal* Notmeta = new WrongAnimal();
	const WrongAnimal* l = new WrongDog();
	const WrongAnimal* s = new WrongCat();
	std::cout << l->getType() << " " << std::endl;
	std::cout << s->getType() << " " << std::endl;
	s->makeSound(); //will output the cat sound!
	l->makeSound();
	Notmeta->makeSound();
}