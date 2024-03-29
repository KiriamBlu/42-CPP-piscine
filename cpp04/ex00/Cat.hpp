
#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class	Cat : public Animal {
	public:

		Cat ( void );
		Cat ( std::string str );
		Cat ( const Cat & var );
		~Cat ( void );

		std::string  getType() const;
		void	makeSound() const;

		Cat& operator = (Cat const &var);
};

#endif
