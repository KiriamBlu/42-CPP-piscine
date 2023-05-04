
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string str, int grade): _name( str ) {

  this->gradeCheck(grade);
  this->_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat & var ) {
  *this = var;
}

Bureaucrat::~Bureaucrat( void ) {
  
  std::cout << "Destructor called" << std::endl;

}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &tmp) {
  this->_name = tmp.getName();

  return *this;
}


std::ostream &operator<<(std::ostream& os, const Bureaucrat &tmp){
  os << "I am " << tmp.getName() << " and my grade is " <<  tmp.getGrade();
  return os;
}

void Bureaucrat::signForm( Form &var){
  if (this->_grade <= var.getSigGrade())
  {
    var.beSigned(*this);
    std::cout << this->getName() <<  " signs " << var.getName() << std::endl;
  }
  else
    std::cout << this->getName() << " cannot sign " << var.getName() << " becouse he doesnt have enough clerance level" << std::endl;
}

void Bureaucrat::gradeCheck( int grade ) {
  if ( grade > 150 )
    throw Bureaucrat::GradeTooLowException();
  else if( grade < 1)
    throw Bureaucrat::GradeTooHighException();
}

std::string Bureaucrat::getName( void ) const {
  return this->_name;
}

int Bureaucrat::getGrade( void ) const {
  return this->_grade;
}

void Bureaucrat::plusGrade( void ){
  gradeCheck(this->_grade - 1);
  this->_grade -= 1;
}

void Bureaucrat::minusGrade( void ){
  gradeCheck(this->_grade + 1);
  this->_grade += 1;
}