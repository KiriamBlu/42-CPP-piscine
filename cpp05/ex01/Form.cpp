
#include "Form.hpp"


Form::Form( std::string name, int const sigGrade, int const exeGrade ): _name(name), _signed(0), _sigGrade(sigGrade), _exeGrade(exeGrade){
  this->gradeCheck( sigGrade );
  this->gradeCheck( exeGrade );
}

Form::Form( const Form & var ):  _name(var.getName()),  _signed(var.getSigned()), _sigGrade(var.getSigGrade()), _exeGrade(var.getExeGrade()) {
  
}

Form::~Form( void ) {
  std::cout << "Destructor called" << std::endl;
  return ;
}


Form & Form::operator=(const Form &tmp) {
  this->_signed = tmp.getSigned();
  return (*this);
  
}

std::ostream &operator<<(std::ostream& os, const Form &tmp) {
  os << std::endl << "Form:" << tmp.getName() << std::endl << "Signned: ";
  if (tmp.getSigned() == 0)
    os << "no";
  else
    os << "yes";
  os << std::endl << "Signning grade: " << tmp.getSigGrade() << std::endl << "Execute grade: " << tmp.getExeGrade() << std::endl; 
  return (os);
}

void  Form::beSigned(Bureaucrat const &var){
  if (this->getSigned() == 1)
    std::cout << "This Form has been already signned" << std::endl;
  else if (var.getGrade() <=  this->getSigGrade())
    this->_signed = 1;
  else
    throw Form::GradeTooLowException();
}

std::string Form::getName(void) const{
  return this->_name;
}

int       Form::getSigned( void ) const {
  return (int)this->_signed;
}

int       Form::getSigGrade( void ) const {
  return this->_sigGrade;
}

int       Form::getExeGrade( void ) const {
  return this->_exeGrade;
}

void      Form::gradeCheck( int grade ) const {
  if ( grade > 150 )
    throw Form::GradeTooLowException();
  else if( grade < 1)
    throw Form::GradeTooHighException();
}