#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <string>
#include <iostream>
#include <random>
#include "AForm.hpp"

class	PresidentialPardonForm: public AForm {

	private:
		std::string _target;
	public:

		PresidentialPardonForm 			( const std::string& target );
		PresidentialPardonForm 			( const PresidentialPardonForm & var );
		~PresidentialPardonForm			( void );

		PresidentialPardonForm &operator=	(const PresidentialPardonForm &tmp);
		
		std::string		getTarget(void) const ;
		void			execute(Bureaucrat const &var) const;
};
std::ostream &operator<<(std::ostream& os, const PresidentialPardonForm &tmp);

#endif
