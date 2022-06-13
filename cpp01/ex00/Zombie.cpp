/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string str ) {

  setzombiename( str );

}

Zombie::~Zombie( void ) {
  
  std::cout << this->getzombiename() << " got shot and died" << std::endl;

}

void Zombie::announce( void ) const {

	std::cout << this->getzombiename() << " BRAINZZZZZZZ......" << std::endl;
}

std::string Zombie::getzombiename( void ) const {

	return this->_Zombiename;
}

void	Zombie::setzombiename( std::string str ){

	this->_Zombiename = str;
	return ;
}