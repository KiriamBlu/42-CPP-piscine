#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <string>
#include <iostream>

class	RobotomyRequestForm {

	private:

	public:

		RobotomyRequestForm 			( void );
		RobotomyRequestForm 			( std::string str );
		RobotomyRequestForm 			( const RobotomyRequestForm & var );
		~RobotomyRequestForm			( void );
		RobotomyRequestForm &operator=	(const RobotomyRequestForm &tmp);
};
std::ostream &operator<<(std::ostream& os, const RobotomyRequestForm &tmp);

#endif
