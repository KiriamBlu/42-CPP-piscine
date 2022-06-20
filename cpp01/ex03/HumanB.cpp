/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

//--------------------------Basic_constructor_destructor---------------------------------------------

HumanB::HumanB( std::string name ) : _name(name){
  
}

HumanB::~HumanB( void ) {
  
}

//-----------------------------------Functions------------------------------------------------------

void HumanB::attack( void ) {

	std::cout << this->_name << " attacks with his " << this->_Weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon& newWeapon ){

	this->_Weapon = &newWeapon;
}