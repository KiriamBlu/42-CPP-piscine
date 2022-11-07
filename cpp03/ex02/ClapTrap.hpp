#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class	ClapTrap {

	private:
		std::string _name;
		int 		_healthpoints;
		int			_energypoints;
		int			_damage;
	public:

		std::string get_Name(void) const;
		int get_Hp(void) const;
		int get_Stamina(void) const;
		int get_Dmg(void) const;

		void set_Name(std::string new_name);
		void set_Hp(int new_hp);
		void set_Stamina(int new_stamina);
		void set_Dmg(int new_Dmg);

		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void announce_hp_left(void);

		ClapTrap& operator = (ClapTrap const &var);

		ClapTrap ( void );
		ClapTrap ( std::string str );
		ClapTrap ( const ClapTrap & var );
		~ClapTrap ( void );
};

#endif
