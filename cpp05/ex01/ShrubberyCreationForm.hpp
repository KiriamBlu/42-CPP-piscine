#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <string>
#include <iostream>

class	ShrubberyCreationForm {

	private:

	public:

		ShrubberyCreationForm 			( void );
		ShrubberyCreationForm 			( std::string str );
		ShrubberyCreationForm 			( const ShrubberyCreationForm & var );
		~ShrubberyCreationForm			( void );
		ShrubberyCreationForm &operator=	(const ShrubberyCreationForm &tmp);
};
std::ostream &operator<<(std::ostream& os, const ShrubberyCreationForm &tmp);

#endif
