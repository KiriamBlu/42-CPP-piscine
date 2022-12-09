
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include <string>
#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"



class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class	MateriaSource: public IMateriaSource {

	private:
		void init_inventory( void );
		void copy_inventory( const MateriaSource & var );
		void free_inventory( void );
		AMateria*	_inventory[4];

	public:

		MateriaSource ( void );
		MateriaSource ( const MateriaSource & var );
		~MateriaSource ( void );
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
		MateriaSource &operator=(const MateriaSource &tmp);
};
#endif
