
#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP
#include <string>
#include <iostream>

class AMateria;
class ICharacter {

	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip( AMateria* m ) = 0;
		virtual void unequip( int idx ) = 0;
		virtual void use( int idx, ICharacter& target ) = 0;
};

class Character : public ICharacter {

	private:
		void init_inventory( void );
		void copy_inventory( const Character & var );
		void free_inventory( void );
		AMateria*	_inventory[4];
		std::string _identity;
	public:
		Character( void );
		Character( std::string const name );
		Character( const Character & var );
		~Character( void );

		std::string const & getName( void ) const;
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter& target );

		Character& operator = (Character const &var);
};
#endif