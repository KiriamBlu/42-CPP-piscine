/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_var.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact_var.hpp"

contact_var::contact_var( void ) {

  return ;
  
}

contact_var::~contact_var(void) {
  
  return ;

}

void contact_var::setdata(std::string type, std::string info) {
	if (type.compare("first_name") == 0)
		this->first_name = info;
	if (type.compare("last_name") == 0)
		this->last_name = info;
	if (type.compare("nickname") == 0)
		this->nickname = info;
	if (type.compare("phone_nbr") == 0)
		this->phone_nbr = info;
	if (type.compare("dark_secret") == 0)
		this->dark_secret = info;
}

std::string contact_var::getdata(std::string type) {

	std::string	ret;

	if (type.compare("first_name") == 0)
		ret = this->first_name;
	if (type.compare("last_name") == 0)
		ret = this->last_name;
	if (type.compare("nickname") == 0)
		ret = this->nickname;
	if (type.compare("phone_nbr") == 0)
		ret = this->phone_nbr;
	if (type.compare("dark_secret") == 0)
		ret = this->dark_secret;
	return ret;
}
