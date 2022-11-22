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
		std::string  getType() const;
		virtual void	makeSound() const;
		void set_type( const std::string var ) ;

		Animal& operator = (Animal const &var);
};

#endif
