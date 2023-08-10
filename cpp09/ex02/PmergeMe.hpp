
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <string>
#include <iostream>

// Std list
// Std vector

class	PmergeMe {

	private:

	public:

		PmergeMe 			( void );
		PmergeMe 			( std::string str );
		PmergeMe 			( const PmergeMe & var );
		~PmergeMe			( void );
		PmergeMe &operator=	(const PmergeMe &tmp);
};
std::ostream &operator<<(std::ostream& os, const PmergeMe &tmp);

#endif
