
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>

class	Zombie {

	private:
		std::string	_Zombiename;
	public:

		Zombie ( std::string str );
		~Zombie ( void );

		void 	announce( void ) const;

		std::string getzombiename( void ) const;
		void	setzombiename( std::string str ) ;
};

Zombie* zombieHorde( int N, std::string name );

#endif
