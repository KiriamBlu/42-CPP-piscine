
#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {

	private:
		std::string const _name;
		bool _signed;
		int const _sigGrade;
		int const _exeGrade;
	public:
		Form 			( std::string const name, int const igGrade, int const exeGrade );
		Form 			( const Form & var );
		~Form			( void );
		Form &operator=	(const Form &tmp);

		void			beSigned(Bureaucrat const &var);
		std::string 	getName(void) const;
		int				getSigned( void ) const;
		int 			getSigGrade( void ) const;
		int 			getExeGrade( void ) const;
		void			gradeCheck( int grade ) const;


		class GradeTooHighException : public std::exception{
			public:
				virtual const char* throwException() const throw() {
					return ( "Required a higher grade" );
				}
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char* throwException() const throw() {
					return ( "Not enough grade" );
				}
		};
};
std::ostream &operator<<(std::ostream& os, const Form &tmp);

#endif
