
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>

class	Bureaucrat {

	private:
	 	std::string _name;
		int _grade;
	public:

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* throwException() const throw() {
					return ( "This grade is not archiveable" );
				}
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char* throwException() const throw() {
					return ( "This grade ist posible" );
				}
		};
		void gradeCheck( int grade );
		std::string getName( void ) const;
		int getGrade( void ) const;
		void plusGrade( int const & sum );
		void minusGrade( int const & sub );

		Bureaucrat ( std::string str, int grade );
		Bureaucrat ( const Bureaucrat & var );
		~Bureaucrat ( void );
		Bureaucrat &operator=(const Bureaucrat &tmp);
};
std::ostream &operator<<(std::ostream& os, const Bureaucrat &tmp);

#endif
