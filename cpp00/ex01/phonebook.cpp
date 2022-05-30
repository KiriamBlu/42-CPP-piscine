/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

phonebook::phonebook( void ) {

  std::cout << "WELCOME TO THE MOST AMAZING MORE EFFECTIVE AND LOGIC AGENDA" << std::endl;
  std::cout << "-----------------------------------------------------------" << std::endl;
  std::cout << std::endl;
  return ;
}

phonebook::~phonebook(void) {
  
  std::cout << "BY BY IT WAS NICE TALKING TO YOU" << std::endl;
  return ;
}

void	phonebook::phonebook_start(void)
{
	std::string	str;

	while(420)
	{
		std::cout << "Write the instruction(ADD, SEARCH, EXIT) that you wish to perform" << std::endl;
		std::cout << "phonebook > ";
		std::cin >> str;
		std::cout << std::endl;
		if (!str.compare("ADD"))	
		{
			std::cout << "Lest add a new friend" << std::endl;
			//aqui añadir el settear un nuevo contacto
		}
		if (!str.compare("EXIT"))
			exit(0);

	}
}

