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

void	phonebook::phonebook_start(void){
	
	std::string	str;

	while(790)
	{
		std::cout << "Write the instruction(ADD, SEARCH, EXIT) that you wish to perform" << std::endl;
		std::cout << "phonebook > ";
		std::cin >> str;
		std::cout << std::endl;
		if (!str.compare("ADD"))	
		{
			std::cout << "Lest add a new friend" << std::endl << std::endl;
			std::cout << "---------------------" << std::endl;
			this->getaddvariables();
		}
		if (!str.compare("SEARCH"))
		{
			std::cout << "Everything you need to know is down here" << std::endl << std::endl;
			this->getsearchvariables();
		}
		if (!str.compare("EXIT"))
			exit(0);

	}
}

void	phonebook::getaddvariables(void){
	
	std::string	filler;
	int			num;

	while("NOT FINISHED")
	{
		num = this->numcontacts;
		std::cout << "Write the first name" << std::endl;
		std::cout << "INFO > ";
		std::cin >> filler;
		this->contacts[num].setdata("first_name", filler);
		
		std::cout << "Write the last name" << std::endl;
		std::cout << "INFO > ";
		std::cin >> filler;
		this->contacts[num].setdata("last_name", filler);
		
		std::cout << "Write the nickname" << std::endl;
		std::cout << "INFO > ";
		std::cin >> filler;
		this->contacts[num].setdata("nickname", filler);
		
		std::cout << "Write the phone number" << std::endl;
		std::cout << "INFO > ";
		std::cin >> filler;
		this->contacts[num].setdata("phone_nbr", filler);

		std::cout << "Write the dark secret" << std::endl;
		std::cout << "INFO > ";
		std::cin >> filler;
		this->contacts[num].setdata("dark_secret", filler);

		std::cout << std::endl << "Is this info right?" << std::endl;
		std::cout << "-------------------" << std::endl;
		std::cout << "First name: " << this->contacts[num].getdata("first_name") << std::endl;
		std::cout << "Last name: " << this->contacts[num].getdata("last_name") << std::endl;
		std::cout << "Nickname: " << this->contacts[num].getdata("nickname") << std::endl;
		std::cout << "Phone number: " << this->contacts[num].getdata("phone_nbr") << std::endl;
		std::cout << "Dark secret: " << this->contacts[num].getdata("dark_secret") << std::endl;
		std::cout << "-------------------" << std::endl << std::endl;

		while(filler.compare("YES") || filler.compare("NO"))
		{
			std::cout << "Write (YES) to confirm or (NO) to try again: ";
			std::cin >> filler;
			std::cout << std::endl;
			if (!filler.compare("YES"))
			{
				if (this->numcontacts < MAX_CONTACTS)
					this->numcontacts += 1;
				return ;
			}
			else if (!filler.compare("NO"))
				break;
		}
	}
}

void	display(std::string print){
	std::cout << std::setw(10)
	std::cout << print

}

void	phonebook::getsearchvariables(void){

	if (this->numcontacts == 0)
		std::cout << std::endl << "-----------NO CONTACTS REGISTERED-----------" << std::endl << std::endl;
	else{

	}

}

