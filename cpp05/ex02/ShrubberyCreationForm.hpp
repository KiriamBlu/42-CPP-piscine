#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <string>
#include <iostream>
#include "Form.hpp"

class	ShrubberyCreationForm: public Form {

	private:
		const std::string _target;
	public:

		ShrubberyCreationForm 			( void );
		ShrubberyCreationForm 			( const ShrubberyCreationForm & var );
		~ShrubberyCreationForm			( void );

		ShrubberyCreationForm &operator=	(const ShrubberyCreationForm &tmp);
		
		std::string		getTarget(void);
		void			execute(Bureaucrat &var) const;
};
std::ostream &operator<<(std::ostream& os, const ShrubberyCreationForm &tmp);

#endif
