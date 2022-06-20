/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//--------------------------Basic_constructor_destructor---------------------------------------------

Weapon::Weapon( std::string type ) : _type(type) {

  
}

Weapon::~Weapon( void ) {
  

}

//------------------------------------getter----------------------------------------------------------

std::string const &Weapon::getType( void ){

	return this->_type;
}

void Weapon::setType( std::string nuts ) {

	this->_type = nuts;
}