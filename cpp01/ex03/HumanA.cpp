/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//--------------------------Basic_constructor_destructor---------------------------------------------

HumanA::HumanA( std::string name, Weapon type ) : _name(name) {

	
  this->_Weapon = &type;
}

HumanA::~HumanA( void ) {

}

//-----------------------------------Functions------------------------------------------------------

void HumanA::attack( void ) {

	std::cout << this->_name << " attacks with his " << this->_Weapon->getType() << std::endl;
}

void HumanA::setWeapon( Weapon& newWeapon ){

	this->_Weapon = &newWeapon;
}