/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP
#include <iostream>


template <typename T> 
T max(T a, T b){
	return (a > b) ? a : b;
}

template <typename T> 
T min(T a, T b){
	return (a < b) ? a : b;
}

template <typename T> 
void swap(T &a, T &b){
	T aux;


	aux	= a;
	a = b;
	b = aux;
}

#endif