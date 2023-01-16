#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <string>
#include <iostream>

class	PresidentialPardonForm {

	private:

	public:

		PresidentialPardonForm 			( void );
		PresidentialPardonForm 			( std::string str );
		PresidentialPardonForm 			( const PresidentialPardonForm & var );
		~PresidentialPardonForm			( void );
		PresidentialPardonForm &operator=	(const PresidentialPardonForm &tmp);
};
std::ostream &operator<<(std::ostream& os, const PresidentialPardonForm &tmp);

#endif
