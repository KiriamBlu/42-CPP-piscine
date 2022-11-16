
#ifndef WrongDOG_HPP
#define WrongDOG_HPP
#include "WrongAnimal.hpp"

class	WrongDog : public WrongAnimal{
	public:

		WrongDog ( void );
		WrongDog ( std::string str );
		WrongDog ( const WrongDog & var );
		~WrongDog ( void );

		std::string  getType() const;
		void	makeSound() const;

		WrongDog& operator = (WrongDog const &var);
};

#endif
