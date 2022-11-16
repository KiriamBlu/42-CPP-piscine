
#ifndef WrongCAT_HPP
#define WrongCAT_HPP
#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	public:

		WrongCat ( void );
		WrongCat ( std::string str );
		WrongCat ( const WrongCat & var );
		~WrongCat ( void );

		std::string  getType() const;
		void	makeSound() const;

		WrongCat& operator = (WrongCat const &var);
};

#endif
