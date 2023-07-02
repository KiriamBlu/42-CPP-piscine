#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) {

  std::cout << "Default constructor called" << std::endl;
  
}

BitcoinExchange::BitcoinExchange( std::string str ) {

  std::cout << "Parameter constructor called" << std::endl;
  
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & var ) {

  std::cout << "Copy constructor called" << std::endl;
  
}

BitcoinExchange::BitcoinExchange~( void ) {
  
  std::cout << "Destructor constructor called" << std::endl;

}
