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
#include <iomanip>
#include <stdlib.h>

std::string	*fillermat( void );
void		display( std::string print );
int			numberchecker(std::string filler);

phonebook::phonebook( void ) {

  std::cout << std::endl;
  std::cout << "WELCOME TO THE MOST AMAZING MORE EFFECTIVE AND LOGIC AGENDA" << std::endl;
  std::cout << "-----------------------------------------------------------" << std::endl;
  std::cout << std::endl;
  return ;
}

phonebook::~phonebook( void ) {
  
  std::cout << "BY BY IT WAS NICE TALKING TO YOU" << std::endl;
  return ;
}

//------------------------------------BASIC_FUNCTIONS-------------------------------------//

void	phonebook::phonebook_start(void){
	
	std::string	str;

	while(42)
	{
		std::cout << "Write the instruction(ADD, SEARCH, EXIT) that you wish to perform" << std::endl;
		std::cout << "phonebook > ";
		if(!std::getline( std::cin, str ))
 			exit(0);
		std::cout << std::endl;
		if ( !str.compare( "ADD" ) )	
		{
			std::cout << "Let's add a new friend" << std::endl << std::endl;
			std::cout << "----------------------" << std::endl;
			if ( this->getaddvariables() )
			{
				std::cout << std::endl;
				break;
			}
		}
		else if ( !str.compare( "SEARCH" ) )
		{
			std::cout << "Everything you need to know is down here" << std::endl << std::endl;
			this->getsearchvariables();
		}
		else if ( !str.compare( "EXIT" ) )
			break ;
		else
			std::cout << "Not a valid option" << std::endl;
	}
}

int	phonebook::getaddvariables( void ){
	
	std::string	filler;
	int			num;

	while( "NOT FINISHED" )
	{
		num = ( this->numcontacts % 8 );
		std::cout << "Write the first name" << std::endl;
		std::cout << "INFO > ";
		if ( !std::getline( std::cin, filler ) )
			exit(0);
		this->contacts[num].setdata( "first_name", filler );
		
		std::cout << "Write the last name" << std::endl;
		std::cout << "INFO > ";
		if ( !std::getline( std::cin, filler ) )
			exit(0);
		this->contacts[num].setdata( "last_name", filler );
		
		std::cout << "Write the nickname" << std::endl;
		std::cout << "INFO > ";
		if ( !std::getline( std::cin, filler ) )
			exit(0);
		this->contacts[num].setdata( "nickname", filler );
		
		std::cout << "Write the phone number" << std::endl;
		std::cout << "INFO > ";
		if ( !std::getline( std::cin, filler ) )
			exit(0);
		while ( numberchecker(filler) == 1 )
		{
			std::cout << "Not valid number, please try again" << std::endl;
			std::cout << "INFO > ";
			!std::getline( std::cin, filler );
			if (!filler.compare( "\0" ) )
				exit(0);
		}
		this->contacts[num].setdata( "phone_nbr", filler );

		std::cout << "Write the dark secret" << std::endl;
		std::cout << "INFO > ";
		if ( !std::getline( std::cin, filler ) )
			exit(0);
		this->contacts[num].setdata( "dark_secret", filler );

		if ( userfinish( num ) )
			return 1;
		return 0;
	}	
}

int	phonebook::userfinish( int num )
{
	std::string	filler;

	std::cout << std::endl << "Is this info right?" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "First name: " << this->contacts[num].getdata( "first_name" ) << std::endl;
	std::cout << "Last name: " << this->contacts[num].getdata( "last_name" ) << std::endl;
	std::cout << "Nickname: " << this->contacts[num].getdata( "nickname" ) << std::endl;
	std::cout << "Phone number: " << this->contacts[num].getdata( "phone_nbr" ) << std::endl;
	std::cout << "Dark secret: " << this->contacts[num].getdata( "dark_secret" ) << std::endl;
	std::cout << "-------------------" << std::endl << std::endl;

	while( filler.compare( "YES" ) || filler.compare( "NO" ) )
	{
	std::cout << "Write (YES) to confirm or (NO) to try again: ";
	if ( !std::getline( std::cin, filler ) )
		exit(0);
	std::cout << std::endl;
	if ( !filler.compare( "YES" ) )
	{
			if ( this->realcontacts < 8 )
				this->realcontacts++;
			this->numcontacts += 1;
			return 0;
		}
		else if ( !filler.compare( "NO" ) )
			break;
	}
	return 0;
}

void	phonebook::getsearchvariables(void){

	int filler;

	if ( this->numcontacts == 0 )
		std::cout << std::endl << "-----------NO CONTACTS REGISTERED-----------" << std::endl << std::endl;
	else
	{	
		std::string *helper = fillermat();
		for ( int x = 0; x < realcontacts; ++x )
		{
			std::cout << '|';
			display(std::to_string( x + 1 ));
			std::cout << '|';
			for ( int i = 0; i < 3; ++i )
			{
				display( this->contacts[x].getdata( helper[i] ) );
				std::cout << '|';	
			}
			std::cout << std::endl;
		}
		std::cout << "---------------------------------------------" << std::endl << std::endl;
		std::cout << "To expand the info of the contact input the index (if you dont want to expand any just press 0): ";
		std::cin >> filler;
		std::cout << std::endl;
		if ( !filler )
		{
			std::cin.ignore();
			delete [] helper;
			return ;
		}
		else if ( filler > 0 && filler < 9 )
		{
			if ( filler > this->numcontacts )
			{
				std::cout << "You entered and invalid contact" << std::endl;
				delete [] helper;
				std::cin.ignore();
				return ;
			}
			for ( int i = 0; i < 5; ++i )
			{
				std::cout << helper[i] << ": ";
				std::cout << this->contacts[filler - 1].getdata( helper[i] ) << std::endl;;
			}
		}
		std::cout << std::endl;
		delete [] helper;
		std::cin.ignore();
		return ;
	}
}

//--------------------------------------AUX_FUNTIONS----------------------------------------//

void	display( std::string print )
{
	if ( print.length() > 10 )
	{
		for ( int x = 0; x < 9; x++ )
			std::cout << print[x];
		std::cout << ".";	
	}
	else
	{
		std::cout << std::setw( 10 );
		std::cout << print;
	}
}

std::string *fillermat( void )
{
	std::string *aux;

	aux = new std::string[5];
	aux[0] = "first_name";
	aux[1] = "last_name";
	aux[2] = "nickname";
	aux[3] = "phone_nbr";
	aux[4] = "dark_secret";
	std::cout << "---------------------------------------------";
	std::cout << std::endl;
	std::cout << '|';
	display( "INDEX" );
	std::cout << '|';
	display( "NAME" );
	std::cout << '|';
	display( "LST_NAME" );
	std::cout << '|';
	display( "NICKNAME" );
	std::cout << '|';
	std::cout << std::endl;
	std::cout << "|----------|----------|----------|----------|";
	std::cout << std::endl;
	return ( aux );
}

int numberchecker(std::string filler)
{
	for (unsigned long x = 0; x < filler.length(); x++)
		if ( !std::isdigit((int)filler[x]) )
			return (1);
	return (0);
}


