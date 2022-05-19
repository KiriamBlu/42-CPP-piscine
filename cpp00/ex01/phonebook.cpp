/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

phonebook::phonebook( void ) {

  std::cout << "Default constructor called" << std::endl;
  
}

phonebook::phonebook( std::string str ) {

  std::cout << "Parameter constructor called" << std::endl;
  
}

phonebook::phonebook( const phonebook & var ) {

  std::cout << "Copy constructor called" << std::endl;
  
}

phonebook::phonebook~( void ) {
  
  std::cout << "Destructor constructor called" << std::endl;

}
