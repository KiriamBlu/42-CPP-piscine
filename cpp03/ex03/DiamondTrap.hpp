#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public ScavTrap , public FragTrap {

	private:
		std::string _name;
	public:

		DiamondTrap ( void );
		DiamondTrap ( std::string str );
		DiamondTrap ( const DiamondTrap & var );
		~DiamondTrap ( void );

		void attack( std::string const & name );
		void set_Name( std::string new_name );
		std::string get_Name(void) const;

		void whoAmI( void );
		DiamondTrap&	operator = ( DiamondTrap const &other );
};

#endif
