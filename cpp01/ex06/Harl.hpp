/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Harl_HPP
#define Harl_HPP
#include <string>
#include <iostream>
#include <vector>

class	Harl {

	private:
		void DEBUG( void );
		void INFO( void );
		void WARNING( void );
		void ERROR( void );
	public:
		void complain( std::string level );
		Harl ( void );
		~Harl ( void );
};

void Harlfilter( std::string level );

#endif
