#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <string>
#include <iostream>

class	ScavTrap : public ClapTrap {

	private:
		
	public:

		ScavTrap ( void );
		ScavTrap ( std::string str );
		ScavTrap ( const ScavTrap & var );
		~ScavTrap ( void );

		void guardGate( void );
};

#endif
