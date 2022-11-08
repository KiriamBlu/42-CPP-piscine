
#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class	Dog : public Animal{
	public:

		Dog ( void );
		Dog ( std::string str );
		Dog ( const Dog & var );
		~Dog ( void );

		std::string  get_type();
		void	makeSound();

		Dog& operator = (Dog const &var);
};

#endif
