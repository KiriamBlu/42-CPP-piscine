#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {

	private:
		
	public:

		ScavTrap ( void );
		ScavTrap ( std::string str );
		ScavTrap ( const ScavTrap & var );
		~ScavTrap ( void );

		void attack( std::string const name );
		void guardGate( void );

		ScavTrap&	operator = ( ScavTrap const &other );
};

#endif