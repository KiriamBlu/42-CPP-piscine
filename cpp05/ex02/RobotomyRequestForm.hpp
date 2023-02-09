#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <string>
#include <iostream>
#include "Form.hpp"

class	RobotomyRequestForm: public Form {

	private:

	public:

		RobotomyRequestForm 			( void );
		RobotomyRequestForm 			( const RobotomyRequestForm & var );
		~RobotomyRequestForm			( void );
		RobotomyRequestForm &operator=	(const RobotomyRequestForm &tmp);
};
std::ostream &operator<<(std::ostream& os, const RobotomyRequestForm &tmp);

#endif
