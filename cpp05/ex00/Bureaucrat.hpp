
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>

class	Bureaucrat {

	private:
	 	std::string const _name;
		int _grade;
	public:

		Bureaucrat ( void );
		Bureaucrat ( std::string str );
		Bureaucrat ( const Bureaucrat & var );
		~Bureaucrat ( void );
		Bureaucrat &operator=(const Bureaucrat &tmp);
};
std::ostream &operator<<(std::ostream& os, const Bureaucrat &tmp);

#endif
