/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP
#include <string>
#include <iostream>
#include <vector>

class	Karen {

	private:
		void DEBUG( void );
		void INFO( void );
		void WARNING( void );
		void ERROR( void );
	public:
		void complain( std::string level );
		Karen ( void );
		~Karen ( void );
};

void karenfilter( std::string level );

#endif