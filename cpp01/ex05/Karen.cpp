/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen( void ) {

  std::cout << "Default constructor called" << std::endl;
  
}

Karen::Karen( std::string str ) {

  std::cout << "Parameter constructor called" << std::endl;
  
}

Karen::Karen( const Karen & var ) {

  std::cout << "Copy constructor called" << std::endl;
  
}

Karen::~Karen( void ) {
  
  std::cout << "Destructor constructor called" << std::endl;

}
