#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <string>
#include <iostream>
#include "Form.hpp"

class	PresidentialPardonForm: public Form {

	private:
		Bureaucrat target;
	public:

		PresidentialPardonForm 			( void );
		PresidentialPardonForm 			( const PresidentialPardonForm & var );
		~PresidentialPardonForm			( void );
		PresidentialPardonForm &operator=	(const PresidentialPardonForm &tmp);
};
std::ostream &operator<<(std::ostream& os, const PresidentialPardonForm &tmp);

#endif
