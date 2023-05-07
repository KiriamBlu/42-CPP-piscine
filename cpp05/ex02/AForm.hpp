
#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm {

	private:
		std::string const _name;
		bool _signed;
		int const _sigGrade;
		int const _exeGrade;
	public:
				AForm 			( std::string const name, int const igGrade, int const exeGrade );
				AForm 			( const AForm & var );
		virtual ~AForm			( void );
		AForm &operator=	(const AForm &tmp);

		virtual void	execute(Bureaucrat const &var) const = 0;
		void			beSigned(Bureaucrat const &var);
		std::string 	getName(void) const;
		int				getSigned( void ) const;
		int 			getSigGrade( void ) const;
		int 			getExeGrade( void ) const;
		void			gradeCheck( int grade ) const;
		void 			checkSigned( int check )const;


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

		class AFormNotSigned : public std::exception{
			public:
				virtual const char* throwException() const throw() {
					return ( "This Aform cant be executed, it isnt signed" );
				}
		};
};
std::ostream &operator<<(std::ostream& os, const AForm &tmp);

#endif
