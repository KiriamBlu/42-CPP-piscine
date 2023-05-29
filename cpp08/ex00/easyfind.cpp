#include "easyfind.hpp"

easyfind::easyfind( void ) {

  std::cout << "Default constructor called" << std::endl;
  
}

easyfind::easyfind( std::string str ) {

  std::cout << "Parameter constructor called" << std::endl;
  
}

easyfind::easyfind( const easyfind & var ) {

  std::cout << "Copy constructor called" << std::endl;
  
}

easyfind::easyfind~( void ) {
  
  std::cout << "Destructor constructor called" << std::endl;

}
