
#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include <iostream>

class ICharacter;
class AMateria {
	protected:
		std::string _type;
	public:
		AMateria( void );
		AMateria( std::string const & type );
		AMateria( const AMateria & var );
		virtual ~AMateria( void );

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		AMateria& operator = (AMateria const &var);
};


class Ice : public AMateria {
	public:
		Ice( void );
		Ice( std::string const & type );
		Ice( const Ice & var );
		~Ice( void );

		std::string const & getType() const;
		AMateria* clone() const;
		void use(ICharacter&);

		Ice& operator = (Ice const &var);
};

class Cure : public AMateria {
	public:
		Cure( void );
		Cure( std::string const & type );
		Cure( const Cure & var );
		~Cure( void );

		std::string const & getType() const;
		AMateria* clone() const;
		void use(ICharacter&);

		Cure& operator = (Cure const &var);
};

#endif