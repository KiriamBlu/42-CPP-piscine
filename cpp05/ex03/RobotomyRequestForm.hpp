#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <string>
#include <iostream>
#include <random>
#include "AForm.hpp"

class	RobotomyRequestForm: public AForm {

	private:
		std::string _target;
	public:

		RobotomyRequestForm 			( const std::string& target );
		RobotomyRequestForm 			( const RobotomyRequestForm & var );
		~RobotomyRequestForm			( void );

		RobotomyRequestForm &operator=	(const RobotomyRequestForm &tmp);
		
		std::string		getTarget(void) const;
		void			execute(Bureaucrat const &var) const;
};
std::ostream &operator<<(std::ostream& os, const RobotomyRequestForm &tmp);

#endif
