/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                            :+:     :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		virtual ~Form			( void );
		Form &operator=	(const Form &tmp);

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

		class FormNotSigned : public std::exception{
			public:
				virtual const char* throwException() const throw() {
					return ( "This form cant be executed, it isnt signed" );
				}
		};
};
std::ostream &operator<<(std::ostream& os, const Form &tmp);

#endif
