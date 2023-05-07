
#include "AForm.hpp"


AForm::AForm( std::string name, int const sigGrade, int const exeGrade ): _name(name), _signed(0), _sigGrade(sigGrade), _exeGrade(exeGrade){
  this->gradeCheck( sigGrade );
  this->gradeCheck( exeGrade );
}

AForm::AForm( const AForm & var ):  _name(var.getName()),  _signed(var.getSigned()), _sigGrade(var.getSigGrade()), _exeGrade(var.getExeGrade()) {
  
}

AForm::~AForm( void ) {
  std::cout << "Destructor called" << std::endl;
  return ;
}


AForm & AForm::operator=(const AForm &tmp) {
  if(this != &tmp)
    this->_signed = tmp.getSigned();
  return (*this);
  
}

std::ostream &operator<<(std::ostream& os, const AForm &tmp) {
  os << std::endl << "AForm:" << tmp.getName() << std::endl << "Signned: ";
  if (tmp.getSigned() == 0)
    os << "no";
  else
    os << "yes";
  os << std::endl << "Signning grade: " << tmp.getSigGrade() << std::endl << "Execute grade: " << tmp.getExeGrade() << std::endl; 
  return (os);
}


void  AForm::execute(Bureaucrat const &var) const{
  if (this->getSigned() == 0)
    throw AForm::AFormNotSigned();
  if(this->getExeGrade() < var.getGrade())
    throw AForm::GradeTooLowException();
}

void  AForm::beSigned(Bureaucrat const &var){
  if (this->getSigned() == 1)
    std::cout << "This AForm has been already signned" << std::endl;
  else if (var.getGrade() <=  this->getSigGrade())
    this->_signed = 1;
  else
    throw AForm::GradeTooLowException();
}

std::string AForm::getName(void) const{
  return this->_name;
}

int       AForm::getSigned( void ) const {
  return (int)this->_signed;
}

int       AForm::getSigGrade( void ) const {
  return this->_sigGrade;
}

int       AForm::getExeGrade( void ) const {
  return this->_exeGrade;
}

void      AForm::gradeCheck( int grade ) const {
  if ( grade > 150 )
    throw AForm::GradeTooLowException();
  else if( grade < 1)
    throw AForm::GradeTooHighException();
}