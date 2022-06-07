
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "contact_var.hpp"

#define MAX_CONTACTS 8

class	phonebook {

	private:
		int		numcontacts;
		int		realcontacts;
		void	getaddvariables(void);
		void	getsearchvariables(void);
	public:

		contact_var 	contacts[MAX_CONTACTS];
		void	phonebook_start(void);

		phonebook( void );
		~phonebook( void );
};

