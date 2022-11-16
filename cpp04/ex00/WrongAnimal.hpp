

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>
#include <iostream>

class	WrongAnimal {

	protected:
		std::string type;
	public:

		WrongAnimal ( void );
		WrongAnimal ( std::string str );
		WrongAnimal ( const WrongAnimal & var );
		~WrongAnimal ( void );

		std::string  getType() const;
		void	makeSound() const;

		WrongAnimal& operator = (WrongAnimal const &var);
};

#endif
