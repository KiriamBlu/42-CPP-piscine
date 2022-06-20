
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanA {

	private:
		std::string _name;
		Weapon *_Weapon;		
	public:
		void attack( void );
		void setWeapon( Weapon& newWeapon );
		HumanA ( std::string name, Weapon type );
		~HumanA ( void );
};

#endif
