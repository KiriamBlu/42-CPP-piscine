
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {

  std::cout << "Default constructor called" << std::endl;
  
}

Bureaucrat::Bureaucrat( std::string str ) {

  std::cout << "Parameter constructor called" << std::endl;
  
}

Bureaucrat::Bureaucrat( const Bureaucrat & var ) {

  std::cout << "Copy constructor called" << std::endl;
  
}

Bureaucrat::~Bureaucrat( void ) {
  
  std::cout << "Destructor called" << std::endl;

}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &tmp) {

  std::cout << "Operator equalizer called" << std::endl;

}

std::ostream &operator<<(std::ostream& os, const Bureaucrat &tmp) {

	os << std::endl << "Bureaucrat: " << tmp.getName() << std::endl;
	return (os);
  
}

void Bureaucrat::gradeCheck( int grade ); const{
  if ( grade > 150 )
    throw (Bureaucrat::GradeTooLowException);
  else if( grade < 1)
    throw (Bureaucrat::GradeTooHighException);
  return(); 
}

std::string const Bureaucrat::getName( void ) const {
  return this->_name;
}

int const Bureaucrat::getGrade( void ) const {
  return this->_grade;
}

void Bureaucrat::plusGrade(){
  
}

void Bureaucrat::minusGrade(){
  
}