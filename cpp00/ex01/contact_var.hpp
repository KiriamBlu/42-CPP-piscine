
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_var.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_VAR_HPP
#define CONTACT_VAR_HPP
#include <string>
#include <iostream>

class	contact_var {

	private:
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		phone_nbr;
		std::string		dark_secret;

	public:

		void	setdata(std::string type, std::string info);
		std::string	getdata(std::string type);

		contact_var( void );
		~contact_var( void );
};

#endif
