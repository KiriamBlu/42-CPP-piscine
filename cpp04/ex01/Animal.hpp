#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

class	Animal {

	protected:
		std::string type;
	public:

		Animal ( void );
		Animal ( std::string str );
		Animal ( const Animal & var );
		virtual ~Animal ( void );

		virtual std::string  getType() const;
		virtual void	makeSound() const;

		Animal& operator = (Animal const &var);
};

#endif
