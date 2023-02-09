#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <string>
#include <iostream>
#include "Form.hpp"

class	ShrubberyCreationForm: public Form {

	private:

	public:

		ShrubberyCreationForm 			( void );
		ShrubberyCreationForm 			( const ShrubberyCreationForm & var );
		~ShrubberyCreationForm			( void );
		ShrubberyCreationForm &operator=	(const ShrubberyCreationForm &tmp);
};
std::ostream &operator<<(std::ostream& os, const ShrubberyCreationForm &tmp);

#endif
