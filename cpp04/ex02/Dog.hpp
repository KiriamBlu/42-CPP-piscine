
#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal{

	private:
		Brain* DogBrain;

	public:

		Dog ( void );
		Dog ( std::string str );
		Dog ( const Dog & var );
		virtual ~Dog ( void );

		std::string  getType() const;
		virtual void	makeSound() const;

		Dog& operator = (Dog const &var);
};

#endif
