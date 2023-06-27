
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <string>
#include <iostream>


template <typename T>
class	MutantStack {

	private:
		std::stack<T>	storage;

	public:
		iterator 					&end( void );
		iterator				 	&begin( void );
		T 							top( void );
		std::size_t					size( void );
		void						push( const T value );
		void						pop( void );

		MutantStack 				( void );
		MutantStack 				( const std::stack<T> &stack );
		MutantStack 				( const MutantStack &var );
		~MutantStack				( void );
		MutantStack &operator=		( const MutantStack &tmp );

		T& 							getElement(std::size_t index);

		T&							operator[](std::size_t index);
		
		class iterator {
			private:
				MutantStack<T>& stack;
				std::size_t index;

    		public:
        		iterator		(MutantStack<T>& s, std::size_t i);

        		T				&operator*(void) const;
        		iterator		&operator++(void) const;
        		iterator		&operator--(void) const;
        		bool			operator!=(const iterator& other) const;
        		bool			operator==(const iterator& other) const;
		};
};
 
#endif
