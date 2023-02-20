#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Form.hpp"

class	ShrubberyCreationForm: public Form {

	private:
		std::string _target;
	public:

		ShrubberyCreationForm 			( const std::string& target );
		ShrubberyCreationForm 			( const ShrubberyCreationForm & var );
		~ShrubberyCreationForm			( void );

		ShrubberyCreationForm &operator=	(const ShrubberyCreationForm &tmp);
		
		std::string		getTarget(void) const;
		void			execute(Bureaucrat const &var) const;
};
std::ostream &operator<<(std::ostream& os, const ShrubberyCreationForm &tmp);

#endif
