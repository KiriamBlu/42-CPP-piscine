#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public  ClapTrap {

	private:

	public:

		FragTrap ( void );
		FragTrap ( std::string str );
		FragTrap ( const FragTrap & var );
		~FragTrap ( void );

		void	highFivesGuys( void );
		void	attack( std::string const & name );

		FragTrap&	operator = ( FragTrap const &other );
};

#endif
