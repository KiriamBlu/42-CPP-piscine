
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
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
#include <list>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type container_type;
	typedef typename container_type::iterator iterator;
	typedef typename container_type::const_iterator const_iterator;
	typedef typename container_type::reverse_iterator reverse_iterator;
	typedef typename container_type::const_reverse_iterator const_reverse_iterator;

	MutantStack(void){}
	MutantStack(MutantStack const &other): std::stack<T>(other){}
	~MutantStack(void){}

	T &getElement(std::size_t index)
	{
		std::stack<T> tempStack = this->c;

		for (std::size_t i = 0; i < index; i++)
			tempStack.pop();

		return tempStack.top();
	}
	
	T &operator[](std::size_t index){return this->getElement(index);}

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}

	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	}

	reverse_iterator rend()
	{
		return this->c.rend();
	}

	const_iterator cbegin() const
	{
		return this->c.cbegin();
	}

	const_iterator cend() const
	{
		return this->c.cend();
	}

	const_reverse_iterator crbegin() const
    {
        return this->c.crbegin();
    }

    const_reverse_iterator crend() const
    {
        return this->c.crend();
    }

};

#endif

