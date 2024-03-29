/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void writter( std::string str ) {
	std::cout << str << std::endl;
}

Fixed::Fixed( void ) : _decpoint(0) {

	writter("Default constructor called");

}

Fixed::Fixed( const Fixed &var ) {

 	writter("Copy constructor called");
  *this = var;

}

Fixed::~Fixed( void ) {
  
	writter("Destructor constructor called");

}

Fixed & Fixed::operator=(Fixed const &var) {

	writter("Assignation operator called");
	if ( this != &var )
		this->_decpoint = var.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const{

	writter("getRawBits member function called");
	return this->_decpoint;
	
}

void Fixed::setRawBits ( int const raw ){

	this->_decpoint = raw;
}