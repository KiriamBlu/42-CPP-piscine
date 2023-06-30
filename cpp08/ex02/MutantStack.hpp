
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

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	using typename std::stack<T>::stack;
	using typename std::stack<T>::container_type;
	typedef typename std::stack<T>::container_type::iterator iterator;

	T &getElement(std::size_t index)
	{
		std::stack<T> tempStack = this->c;

		for (std::size_t i = 0; i < index; i++)
			tempStack.pop();

		return tempStack.top();
	}
	
	T &operator[](std::size_t index){return this->getElement(index);}

	iterator begin(){
		iterator it = this->c.begin();
		return it;
	}

	iterator end()
	{
		iterator it = this->c.end();
		return it;
	}
};

#endif

