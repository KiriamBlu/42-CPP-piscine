/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen( void ) {

  std::cout << "Karen constructs itself before you" << std::endl;
  
}

Karen::~Karen( void ) {
  
  std::cout << "Karen dissappears infront of you" << std::endl;

}

void Karen::DEBUG ( void ){
  std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
  return ;
}

void Karen::INFO( void ){
  std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!." << std::endl;
  return ;
}

void Karen::WARNING( void ){
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.." << std::endl;
  return ;
}

void Karen::ERROR( void ){
  std::cout << "This is unacceptable, I want to speak to the manager now.. " << std::endl;
  return ;
}


void Karen::complain( std::string level )
{
  //std::cout << level << std::endl;
  std::string w_lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"} ;
  void (Karen::*p_f[])( void ) = {&Karen::DEBUG, &Karen::INFO, &Karen::WARNING, &Karen::ERROR};

  for (int k = 0; k < 4; k++)
  {
    if (w_lvl[k].compare(level) == 0)
    {
      (this->*p_f[k])();
      return ;
    }
  }
  std::cout << "Karen doesnt accept this type of input"<< std::endl;
  return ;
}