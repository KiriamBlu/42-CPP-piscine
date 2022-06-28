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

  std::cout << "Default constructor called" << std::endl;
  
}

Fixed::Fixed( const Fixed &var ) {

  std::cout << "Copy constructor called" << std::endl;
  *this = var;
}

Fixed::~Fixed( void ) {
  
  std::cout << "Destructor constructor called" << std::endl;

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