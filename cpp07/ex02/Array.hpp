
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <string>
#include <iostream>

class	Array {

	private:

	public:

		Array 			( void );
		Array 			( std::string str );
		Array 			( const Array & var );
		~Array			( void );
		Array &operator=	(const Array &tmp);
};
std::ostream &operator<<(std::ostream& os, const Array &tmp);

#endif
