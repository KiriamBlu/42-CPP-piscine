
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
#include <cmath>

class	Fixed {

	private:
		int _decpoint;
		static const int _raw8 = 16;
	public:

		int getRawBits( void ) const;
		void setRawBits ( int const raw ); 
		
		float toFloat( void ) const;
		int toInt( void ) const;
		static const Fixed& max(const Fixed&var2, const Fixed& var1);
		static const Fixed& min(const Fixed&var2, const Fixed& var1);

		Fixed & operator = (Fixed const &var);
		bool operator < (Fixed const &var) const;
		bool operator > (Fixed const &var) const;
		bool operator <= (Fixed const &var) const;
		bool operator >= (Fixed const &var) const;
		bool operator == (Fixed const &var) const;
		bool operator != (Fixed const &var) const;
		Fixed operator + (Fixed const &var);
		Fixed &operator ++ (void);
		Fixed operator ++ (int);
		Fixed operator - (Fixed const &var);
		Fixed &operator -- (void);
		Fixed operator -- (int);
		Fixed operator * (Fixed const &var);
		Fixed operator / (Fixed const &var);
		
		Fixed ( void );
		Fixed ( const Fixed &var );
		Fixed ( const int num );
		Fixed ( const float num );
		~Fixed ( void );
};

std::ostream & operator<<(std::ostream &paco, const Fixed &var);

#endif
