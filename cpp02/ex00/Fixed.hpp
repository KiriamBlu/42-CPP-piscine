
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <iostream>

class	Fixed {

	private:
		int _decpoint;
		static const int _raw8 = 8;
	public:

		int getRawBits( void ) const;
		void setRawBits ( int const raw ); 
		
		Fixed & operator = (Fixed const &var);
		
		Fixed ( void );
		Fixed ( const Fixed &var );
		~Fixed ( void );
};

#endif
